#include "mainwindowserver.h"
#include "ui_mainwindowserver.h"

MainWindowServer::MainWindowServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowServer)
{
    ui->setupUi(this);
    this->setWindowTitle("webCamServer");

    tcpServer = new QTcpServer(this);
    connect(ui->btn_start, SIGNAL(clicked()),this, SLOT(startServer()));
    connect(ui->btn_stop, SIGNAL(clicked()),this, SLOT(stopServer()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    connect(ui->btn_record, SIGNAL(clicked()), this, SLOT(recordVideo()));

    beginWrite = false;
}

MainWindowServer::~MainWindowServer()
{
    delete ui;
}

void MainWindowServer::startServer()
{
    if(tcpServer->isListening())
    {
        QMessageBox::information(this, "Info","Server(" + QString::number(serverPort) + ") already started");
    }
    else
    {
        serverPort = ui->lineEdit_serverPort->text().toInt();
        if(!tcpServer->listen(QHostAddress::Any,serverPort))
        {
            QMessageBox::information(this,"Error","Unable to start the server:"+tcpServer->errorString());
            close();
            return;
        }
    }
}

void MainWindowServer::stopServer()
{
    if(tcpServer->isListening())
    {
        tcpServer->close();

    }
    else
    {
        QMessageBox::information(this, "Info","Server(" + QString::number(serverPort) + ") already close");
    }

    if(tcpServerConnection->isOpen())
    {
        tcpServerConnection->close();
    }
    else
    {
        QMessageBox::information(this, "Info","Server(" + QString::number(serverPort) + ") already close");
    }

    if(writer.isOpened())
    {
        writer.release();
        qDebug()<<"writer released";
        ui->btn_record->setText("record");
    }
}

void MainWindowServer::newConnection()
{
    basize=0;
    tcpServerConnection = tcpServer->nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(ReadData()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(DisplayError(QAbstractSocket::SocketError)));

}

void MainWindowServer::DisplayError(QAbstractSocket::SocketError socketError)
{
    tcpServerConnection->close();
    qDebug() << "server connect error:" << socketError;
}

void MainWindowServer::ReadData()
{
    QByteArray message;

    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_5_9);
    if (basize==0)
    {
        //whether receive 8 bytes, file size
        //until receive 8 full bytes
        if (tcpServerConnection->bytesAvailable()<(int)sizeof(quint64))
        {
            return;
        }
        in>>basize;
    }

    //until receive full msg
    if (quint64(tcpServerConnection->bytesAvailable())<basize)
    {
        return;
    }
    in>>message;
    ShowImage(message);

}

void MainWindowServer::ShowImage(QByteArray receivedData)
{
    QString receivedString = QString::fromLatin1(receivedData.data(),receivedData.size());
    QByteArray decodeByteArray;
    decodeByteArray = QByteArray::fromBase64(receivedString.toLatin1());
    QByteArray uncompressedByteArray = qUncompress(decodeByteArray);
    QImage img;
    img.loadFromData(uncompressedByteArray, "JPEG");
    ui->image->setPixmap(QPixmap::fromImage(img));
    ui->image->resize(img.size());

    basize = 0;

    if(beginWrite)
    {
//        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") <<"img format: " << img.format();
        cv::Mat frame = cv::Mat(img.height(), img.width(), CV_8UC4, img.bits(), img.bytesPerLine()).clone();
        cv::Mat  matNoAlpha;
        cv::cvtColor( frame, matNoAlpha, cv::COLOR_BGRA2BGR );   // drop the all-white alpha channel

        if(!writer.isOpened())
        {
            QString targetVideoPath = qApp->applicationDirPath();
            QString targetVideoName = "video_"+QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss")+".avi";
            QString targetVideo = targetVideoPath + "/" + targetVideoName;
            qDebug()<<"save Video to: " + targetVideo;
            writer.open(targetVideo.toStdString(), CV_FOURCC('M', 'J', 'P', 'G'), 20, cv::Size(img.width(), img.height()), true);
            qDebug()<<"writer opened";
        }

        if(writer.isOpened())
        {
            writer.write(matNoAlpha); // Write frame to VideoWriter
        }
    }
}


void MainWindowServer::recordVideo()
{
    if(beginWrite)
    {
        ui->btn_record->setText("record");
        if(writer.isOpened())
        {
           writer.release();
        }
        qDebug()<<"writer released";
        beginWrite = false;
    }
    else
    {
        ui->btn_record->setText("stop record");
        beginWrite = true;
    }
}
