#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openCamera();
    void readFrameSendData();
    void closeCamera();
    void recordVideo();
    void connectServer();
    void disconnectServer();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QImage qimage;

    cv::VideoCapture capture;
    cv::Mat cvframe;
    cv::VideoWriter writer;
    QTcpSocket* tcpSocket;
    int count;
    QString serverIp;
    int serverPort;
};

#endif // MAINWINDOW_H
