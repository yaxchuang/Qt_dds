#ifndef GET_MODBUS_H
#define GET_MODBUS_H

#include <QThread>
#include <QMutex>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QObject>
#include <QLabel>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialBus/QModbusTcpClient>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDevice>
#include "ooodds.h"
#include "mainwindow_dds.h"
//#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>

class QModbusClient;
class QModbusReply;
class QModbusResponse;

class Get_modbus : public QThread
{
    Q_OBJECT
public:
    Get_modbus(QObject *parent = nullptr, DeviceData *data = nullptr);
    ~Get_modbus();
    void run();
    void SendCommRequest();
    void OpenSerialPort(DeviceData *data);
    void PrepareReadRequest(DeviceData *data);
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    QModbusDataUnit readRequest(int, int, int) const;

public:
    QString portname;
    int deviceid;
    DeviceData *Data_local;
    MyData *data;
    void SetCommPara( QString, int, int, int, int);

private:
    int baudrate;
    int parity;
    int databit;
    int stopbit;
    bool mutex=true;

};

#endif // GET_MODBUS_H
