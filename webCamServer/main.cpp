#include "mainwindowserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowServer w;
    w.show();

    return a.exec();
}
