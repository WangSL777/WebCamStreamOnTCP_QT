#ifndef MAINWINDOWSERVER_H
#define MAINWINDOWSERVER_H

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QException>
#include <QMessageBox>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindowServer;
}

class MainWindowServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowServer(QWidget *parent = 0);
    ~MainWindowServer();

    QTcpServer *tcpServer;
    QTcpSocket *tcpServerConnection;
    QStringList *fortunes;
    QImage *img;
    quint64 basize;

public slots:
    void startServer();
    void stopServer();
    void newConnection();
    void DisplayError(QAbstractSocket::SocketError socketError);
    void ReadData();
    void ShowImage(QByteArray ba);
    void recordVideo();

private:
    Ui::MainWindowServer *ui;
    int serverPort;
    cv::VideoWriter writer;
    bool beginWrite;
};

#endif // MAINWINDOWSERVER_H
