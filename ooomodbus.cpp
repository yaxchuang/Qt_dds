#include "ooomodbus.h"
#include <QtSerialBus/qmodbusdevice.h>
#include <QString>
#include <QObject>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDevice>

Modbus::Modbus(QObject *parent, QString devicename,int deviceid, QString portname, int baudrate, int parity, int databit, int stopbit, int timeout, int retry, QLabel *deviceLabel) : QThread(parent)
{
    this->devicename=devicename;
    this->deviceid=deviceid;
    this->portname=portname;
    this->baudrate=baudrate;
    this->parity=parity;
    this->databit=databit;
    this->stopbit=stopbit;
    this->timeout=timeout;
    this->retry=retry;
    this->deviceLabel=deviceLabel;
}
/*
void Modbus::run()
{
    int startID=0;
    int stopID=1;
    //cout << "modbusDevice: " << modbusDevice <<endl;

    modbusDevice = new QModbusRtuSerialMaster();
    LoadTestPatterns();
    availablePortDetect(QString::number(portNum));

    for (int i = 0; i < availablePorts.length(); i++)
    {
        //cout << "port_number: " << i <<endl;
        for (int j = 0; j < Max_VendorSize; j++)
        {
            //cout << "vendor_number: " << j <<endl;
            if (modbusDevice->state() == QModbusDevice::ConnectedState)
                modbusDevice->disconnectDevice();

            SetCommPara(availablePorts[i], TestPatterns[j].BaudRate, TestPatterns[j].ParityCheck, TestPatterns[j].DataBit, TestPatterns[j].StopBit, TestPatterns[j].Timeout, TestPatterns[j].Retry);

            if (modbusDevice->connectDevice())
            {
                //cout << "connect" <<endl;
                if (modbusDevice->state() == QModbusDevice::ConnectedState)
                {
                    emit StatusUpdate(availablePorts[i] + " Open Successfully" + " VendorID:" + QString::number(j));
                }
            }
            else
            {
                //cout << "disconnect" <<endl;
                emit StatusUpdate(availablePorts[i] + " Connection: " + modbusDevice->errorString() + " VendorID:" + QString::number(j));
                modbusDevice->disconnectDevice();
            }
            for (int k = startID; k <= stopID; k++)
            {
                //cout << "id_number: " << k <<endl;
                if (QModbusReply *reply = modbusDevice->sendReadRequest(readRequest(TestPatterns[j].ModbusRegister, TestPatterns[j].StartAddress, TestPatterns[j].Length), k))
                {
                    //cout << "reply" <<endl;
                    while (!reply->isFinished())
                        QEventLoop().processEvents(QEventLoop::ExcludeUserInputEvents, modbusDevice->timeout());
                    if (!reply)
                        return;
                    if (reply->error() == QModbusDevice::NoError)
                    { //normal response
                        //cout << "normal" <<endl;
                        const QModbusDataUnit unit = reply->result();
                        bool CompareResult = true;
                        if (TestPatterns[j].name != "AUO Battery")
                        {
                            for (int kk = 0; kk < TestPatterns[j].Length; kk++)
                            { //check response
                                if (unit.value(kk) != TestPatterns[j].Response[kk])
                                {
                                    CompareResult = false;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            if (unit.value(0) == 0 && unit.value(2) == 0 && unit.value(4) == 0 && unit.value(6) == 0 &&
                                unit.value(19) == 0 && unit.value(20) == 0 && unit.value(9) != 0 && unit.value(10) != 0 &&
                                unit.value(11) != 0 && unit.value(12) != 0)
                                CompareResult = true;
                            else
                                CompareResult = false;
                        }

                        if (CompareResult)
                        { //device detected
                            emit StatusUpdate(TestPatterns[j].name + " Detected" + "ID=" + QString::number(k));
                            modbusDevice->disconnectDevice();
                            emit DeviceDetected(TestPatterns[j].name, k, availablePorts[i], TestPatterns[j].BaudRate, TestPatterns[j].ParityCheck, TestPatterns[j].DataBit, TestPatterns[j].StopBit, TestPatterns[j].Timeout, TestPatterns[j].Retry);
                            //i=availablePorts.length();
                            j = Max_VendorSize;
                            break;
                        }
                        else //response error
                        {
                            emit StatusUpdate(TestPatterns[j].name + " response error");
                        }
                    }
                    else
                    {
                        //cout << "error" <<endl;
                        //timeout
                        emit StatusUpdate(reply->errorString() + " " + "Vendor Name:" + TestPatterns[j].name + " DeviceID:" + QString::number(k));
                    }
                    //delete reply;
                }
                else
                {
                    //cout << "not_reply" <<endl;
                    emit StatusUpdate("Read error: " + modbusDevice->errorString());
                    //delete reply;
                }
                //QThread::msleep(75);
            }
        }
    }
    //cout << "this->deleteLater();" <<endl;
    this->deleteLater();

}
*/
void Modbus::LoadTestPatterns()  //ok
{
    TestPatterns[0].name = "Relay";
    TestPatterns[0].BaudRate = QSerialPort::Baud19200;
    TestPatterns[0].ParityCheck = QSerialPort::NoParity;
    TestPatterns[0].DataBit = QSerialPort::Data8;
    TestPatterns[0].StopBit = QSerialPort::OneStop;
    TestPatterns[0].ModbusRegister = QModbusDataUnit::HoldingRegisters;

    TestPatterns[1].name = "Meter";
    TestPatterns[1].BaudRate = QSerialPort::Baud9600;
    TestPatterns[1].DataBit = QSerialPort::Data8;
    TestPatterns[1].ParityCheck = QSerialPort::NoParity;
    TestPatterns[1].StopBit = QSerialPort::TwoStop;
    TestPatterns[1].ModbusRegister = QModbusDataUnit::HoldingRegisters;

}
QModbusDataUnit Modbus::readRequest(int funcCode, int startAddress, int numberOfEntries) const
{
    const auto table = static_cast<QModbusDataUnit::RegisterType>(funcCode);
    //cout << QModbusDataUnit(table, startAddress, numberOfEntries).startAddress() <<endl;
    return QModbusDataUnit(table, startAddress, static_cast<quint16>(numberOfEntries));
}
//ok
/*
void Modbus::SetCommPara(QString portName, int baudrate, int parity, int databit, int stopbit, int timeout, int retry)
{
    modbusDevice = new QModbusRtuSerialMaster();
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, portName);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, parity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baudrate);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, databit);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, stopbit);
    modbusDevice->setTimeout(timeout);
    modbusDevice->setNumberOfRetries(retry);
}

void Modbus::availablePortDetect(QString strPortnum) //ok
{
    if (strPortnum == "-1")
    {
        Q_FOREACH (QSerialPortInfo port, QSerialPortInfo::availablePorts())
        {
            if (port.portName().contains("ttyUSB"))
            {
                availablePorts << port.portName();

                //cout << "(-1)(" << port.portName().toStdString() << ")" << endl;
            }
        }
    }
    else
    {
        Q_FOREACH (QSerialPortInfo port, QSerialPortInfo::availablePorts())
        {
            if (port.portName() == "ttyUSB" + strPortnum)
            {
                availablePorts << port.portName();
                break;
                //cout << "(" << strPortnum.toStdString() <<")(" << port.portName().toStdString() << ")" << endl;
            }
        }
    }
}
Modbus::~Modbus()   //ok
{
    availablePorts.clear();
    if (modbusDevice->state() == QModbusDevice::ConnectedState)
        modbusDevice->disconnectDevice();

    delete modbusDevice;
}
*/
