#ifndef OOOMODBUS_H
#define OOOMODBUS_H

#include <QThread>
#include <QString>
#include <QObject>
#include <QtWidgets>
#include <QtCore/qscopedpointer.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialBus/QModbusTcpClient>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDevice>
/*
#include <QtSerialBus/qmodbusclient.h>
#include <QtSerialPort/qserialportglobal.h>
#include <QtSerialPort/qserialport.h>
#include <QtCore/qlist.h>
*/

class QModbusClient;
class QModbusReply;
class Configuration;
class QSerialPort;
class WriteRegisterModel;

struct TestPattern {
    QString name;
    int BaudRate;
    int ParityCheck;
    int DataBit;
    int StopBit;
    int ModbusRegister;
    int StartAddress;
    int Length;
    int Response[10];
    int Timeout;
    int Retry;
    };

class Modbus: public QThread
{
    Q_OBJECT

public:
    explicit Modbus(QObject *parent = nullptr, QString devicename="",int deviceid=0, QString portname="", int baudrate=0, int parity=0, int databit=0,int stopbit=0, int timeout=0,int retry=0, QLabel *deviceLabel=nullptr);
    //~Modbus();
//protected:
    //void run();

public:
    QString portname;
    QString devicename;
    QLabel *deviceLabel;
    void SetCommPara( QString, int, int, int, int, int, int);
    QSerialPortInfo& operator=(const QSerialPortInfo &other);
    void swap(QSerialPortInfo &other);
    int portNum= -1;
    int deviceid;

private:
    void LoadTestPatterns();
    void availablePortDetect(QString);
    QModbusClient *modbusDevice;
    QModbusDataUnit readRequest(int, int, int) const;
    QList<QString> availablePorts;
    const int Max_VendorSize=2;
    struct TestPattern TestPatterns[2];
    int baudrate;
    int parity;
    int databit;
    int stopbit;
    int timeout;
    int retry;
signals:
    void StatusUpdate(QString);
    void DeviceDetected(QString, int,QString,int,int,int,int,int,int);
};

#endif // OOOMODBUS_H
