#ifndef GET_MODBUS_H
#define GET_MODBUS_H

#include <QThread>
#include <QString>
#include <QObject>
#include <QLabel>
#include "ooodds.h"
#include "mainwindow_dds.h"
#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>

class Get_modbus : public QThread
{
    Q_OBJECT
public:
    explicit Get_modbus(DeviceData *data, DeviceData *Data);
    void onModbus(DeviceData *data);
    void run(){
        while(1)
        {
            onModbus(Data_local);
        }
    }

public:
    DeviceData *Data_remote;
    DeviceData *Data_local;
    DeviceData Data_pub;
    DeviceData Data_sub;
    oooDDS *DDS_pub;
    oooDDS *DDS_sub;
//    DeviceData Data_pub;
    MyData *data;

//public slots:
//    void onModbus();
//    void onTimeDisplay();

};
#endif // GET_MODBUS_H
