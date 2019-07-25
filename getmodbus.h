#ifndef GETMODBUS_H
#define GETMODBUS_H

#include <QThread>
#include <QString>
#include <QObject>
#include <QLabel>
#include "ooodds.h"
#include "mainwindow_dds.h"
#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>

class Getmodbus : public QThread
{
    Q_OBJECT
public:
    explicit Getmodbus(DeviceData *data);
    void onModbus(DeviceData *data);
//    void run();
    void run(){
        while(1)
        {
            onModbus(Data_local);
//            exec();
        }
    }

public:
    DeviceData *Data_local;
//    DeviceData Data_pub;
    MyData *data;

//public slots:
//    void onModbus();
//    void onTimeDisplay();

};
#endif // GETMODBUS_H
