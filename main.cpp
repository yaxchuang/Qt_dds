#include "mainwindow_dds.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    // Create a DomainParticipant with default Qos
    QApplication a(argc, argv);
    MainWindow_dds w;
    w.show();
    return a.exec();
}
