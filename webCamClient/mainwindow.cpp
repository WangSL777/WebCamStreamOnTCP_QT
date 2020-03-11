#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("webCamClient");

    timer = new QTimer(this);
    tcpSocket = new QTcpSocket(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(readFrameSendData()));
    connect(ui->btn_start, SIGNAL(clicked()),this, SLOT(openCamera()));
    connect(ui->btn_stop, SIGNAL(clicked()), this, SLOT(closeCamera()));
    connect(ui->btn_record, SIGNAL(clicked()), this, SLOT(recordVideo()));
    connect(ui->btn_connect, SIGNAL(clicked()), this, SLOT(connectServer()));
    connect(ui->btn_disconnect, SIGNAL(clicked()), this, SLOT(disconnectServer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectServer()
{
    qDebug()<<"btn connect clicked";
    serverIp = ui->lineEdit_ip->text();
    serverPort = ui->lineEdit_port->text().toInt();
    qDebug()<<"ip: "<< serverIp << ", port " << serverPort;

    if(tcpSocket->state() == QTcpSocket::ConnectedState)
    {
        QMessageBox::information(this, "Warning","Server(" + serverIp + ": "+ QString::number(serverPort) + ") already connected");
        return;
    }

    try
    {
        tcpSocket->abort();
        tcpSocket->connectToHost(serverIp,serverPort);

        if(tcpSocket->waitForConnected(5000))
        {
           qDebug() << "server connect successful";
        }
        else
        {
           qDebug()<<"server connect failed ";
           QMessageBox::information(this, "Warning","Server(" + serverIp + ": "+ QString::number(serverPort) + ") connect failed");
        }
        count = 0;
    }
    catch(QException &e)
    {
        qDebug()<<"exception: "<< e.what();
    }
}

void MainWindow::disconnectServer()
{
    if(tcpSocket->state() == QTcpSocket::UnconnectedState || tcpSocket->state() == QTcpSocket::ClosingState)
    {
        QMessageBox::information(this, "Warning","Server already disconnected");
    }
    else
    {
        tcpSocket->close();
    }
}

void MainWindow::readFrameSendData()
{
    capture >> cvframe;
    cv::cvtColor(cvframe, cvframe, CV_BGR2RGB);
    qimage = QImage((const uchar*)(cvframe.data), cvframe.cols, cvframe.rows, QImage::Format_RGB888);
    ui->textLabel->setPixmap(QPixmap::fromImage(qimage));
    ui->textLabel->resize(qimage.size());

    //write to file
    if(writer.isOpened())
    {
        writer << cvframe;
    }

    if(tcpSocket->state() == QTcpSocket::ConnectedState && count == 0)
    {
        count = 1;
//        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << ": Server connected, sending data...";
        QByteArray byte;
        QBuffer buf(&byte);
        qimage.save(&buf,"JPEG");
        QByteArray compressByteArray = qCompress(byte,1);
        QByteArray encodedByteArray = compressByteArray.toBase64();

        QByteArray sendByteArray;
        QDataStream outStream(&sendByteArray,QIODevice::WriteOnly);
        outStream.setVersion(QDataStream::Qt_5_9);

        quint64 dataSize = (quint64)(encodedByteArray.size());
        outStream << dataSize;
        outStream << encodedByteArray;
        tcpSocket->write(sendByteArray);
        tcpSocket->flush();

        count = 0;
    }
    else if(count == 1)
    {
        qDebug()<<"count still remain at 1, ignore send data";
    }
}

void MainWindow::openCamera()
{
    if(!capture.isOpened())
    {
        capture = cv::VideoCapture(0);
    }
    else
    {
        qDebug()<<"capture already opened";
    }

    timer->start(33);
}

void MainWindow::closeCamera()
{
    timer->stop();

    if(capture.isOpened())
    {
        capture.release();
    }
    else
    {
        qDebug()<<"capture already released";
    }

    if(writer.isOpened())
    {
        writer.release();
        qDebug()<<"writer released";
        ui->btn_record->setText("record");
    }

}

void MainWindow::recordVideo()
{
    if(!writer.isOpened())
    {
        openCamera();
        cv::Size size = cv::Size(capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT));

        QString targetVideoPath = qApp->applicationDirPath();
        QString targetVideoName = "video_"+QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss")+".avi";
        QString targetVideo = targetVideoPath + "/" + targetVideoName;
        qDebug()<<"save Video to: " + targetVideo;
        writer.open(targetVideo.toStdString(), CV_FOURCC('M', 'J', 'P', 'G'), 20, size, true);
        qDebug()<<"writer opened";
        ui->btn_record->setText("stop record");
    }
    else
    {
        writer.release();
        qDebug()<<"writer released";
        ui->btn_record->setText("record");
    }
}


