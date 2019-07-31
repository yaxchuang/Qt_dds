#include "get_modbus.h"

#include <algorithm>
#include <iostream>

#include <QString>
#include "ooodds.h"
#include <errno.h>
#include <src/include/modbus/modbus.h>
#include <src/include/modbus/modbus-rtu.h>
#include <src/include/modbus/modbus-tcp.h>
#include "qmodbus.h"
#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <unistd.h>

#define On 1
#define G_MSEC_PER_SEC 1000
#define MODBUS_WRITE_REGISTER_CH1 0x01

Get_modbus::Get_modbus(QObject *parent, DeviceData *data):
    Data_remote(data),
    Data_local(data)
{
    onModbus(Data_local);
}

void Get_modbus::onModbus(DeviceData *data)
{
    modbus_t *ctx;
    int nb_addr;
    int flag = 0;

    nb_addr = MODBUS_WRITE_REGISTER_CH1;

//    std::cout << "Writing Relay" <<std::endl;
    ctx = modbus_new_rtu("/dev/ttyUSB1", 9600, 'N', 8, 1);

    modbus_set_slave(ctx, 2);
    modbus_set_debug(ctx, ON);
    sleep(1);
    if (modbus_connect(ctx) == -1) {
        flag = 1;
        modbus_close(ctx);
        modbus_free(ctx);
    }
    std::cout << std::endl;
    std::cout << "NOW current= " << Data_remote->current<<std::endl;
    if(Data_remote->current >=0.45){
        modbus_write_register(ctx, nb_addr, 513);
//        Data_local->status = "Off";
        data->status = "Off";
//        std::cout << "data->status = "<< data->status<<std::endl;
    }
    else{
        modbus_write_register(ctx, nb_addr, 257);
//        Data_local->status = "On";
        data->status = "On";
//        std::cout << "data->status = "<< data->status<<std::endl;
    }
    std::cout<< "Relay of status is " << data->status <<std::endl;

    if(!flag){
        modbus_close(ctx);
        modbus_free(ctx);
    }
    sleep(1);
}

