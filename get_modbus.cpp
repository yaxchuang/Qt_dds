#include "get_modbus.h"
#include <iostream>
#include <QtWidgets>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <rti/util/util.hpp>
#include "ooodds.h"

Get_modbus::Get_modbus(QObject *parent, DeviceData *data):
    QThread (parent),
    Data_local(data)
{
    this->deviceid=1;
    this->portname="/dev/ttyUSB0";
    this->baudrate=QSerialPort::Baud19200;
    this->parity=QSerialPort::NoParity;
    this->databit=QSerialPort::Data8;
    this->stopbit=QSerialPort::OneStop;
}

void Get_modbus::run()
{
    modbusDevice = new QModbusRtuSerialMaster();
    SetCommPara(portname,baudrate,parity,databit,stopbit);
    OpenSerialPort(Data_local);
    while(1)
    {
        sleep(1);
        PrepareReadRequest(Data_local);
    }
}

void Get_modbus::SetCommPara( QString portName, int baudrate, int parity, int databit, int stopbit)
{
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, portName);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, parity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baudrate);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, databit);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, stopbit);

}

void Get_modbus::OpenSerialPort(DeviceData *data)
{
    modbusDevice->connectDevice();
    modbusDevice->disconnectDevice();
    if (modbusDevice->connectDevice())
    {
        if(modbusDevice->state()== QModbusDevice::ConnectedState)
        {}
    }
    else
    {
        data->voltage = (-1.0);
        data->current = (-1.0);
        data->power = (-1.0);
        data->frequency = (-1.0);
        data->pf = (-1.0);
        data->status = "Off";
        modbusDevice->disconnectDevice();
    }
}

void Get_modbus::PrepareReadRequest(DeviceData *data)
{
    mutex=false;
    if (!modbusDevice)
        return;
    if(auto *reply = modbusDevice->sendReadRequest(readRequest(QModbusDataUnit::HoldingRegisters, 20, 27), deviceid))
    {
        while(!reply->isFinished())
            QEventLoop().processEvents(QEventLoop::ExcludeUserInputEvents, modbusDevice->timeout());
        if (reply->error() == QModbusDevice::NoError)
        {
            const QModbusDataUnit unit = reply->result();
            data->id = (0);
            data->current = (unit.value(6)*0.1f*4/100);
            data->voltage = (unit.value(0)*0.1f);
            data->power = (unit.value(10)*0.1f*4);
            data->frequency = (unit.value(26)*0.1f/10);
            data->pf = (unit.value(22)*0.1f/100);
            data->status = "On";
            std::cout << "modbusread~~~~"<<std::endl;
            std::cout << "Voltage is "<< data->voltage <<std::endl;
            std::cout << "Current is "<< data->current <<std::endl;
            std::cout << "Power is "<< data->power <<std::endl;
            std::cout << "Frequency is "<< data->frequency <<std::endl;
            std::cout << "PF is "<< data->pf <<std::endl;
            std::cout << std::endl;
        }
    }
}

QModbusDataUnit Get_modbus::readRequest(int funcCode, int startAddress, int numberOfEntries) const
{
    const auto table = static_cast<QModbusDataUnit::RegisterType> (funcCode);
    return QModbusDataUnit(table, startAddress, static_cast<quint16>(numberOfEntries));
}

Get_modbus::~Get_modbus()
{
    if (modbusDevice->state()== QModbusDevice::ConnectedState) {
        while  (!mutex)
//           sleep(1500)
                   ;
        modbusDevice->disconnectDevice();
    }
    modbusDevice->deleteLater();
}
