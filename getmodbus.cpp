#include "getmodbus.h"

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

#define G_MSEC_PER_SEC 1000
#define MODBUS_READ_REGISTERS_VOLTAGE 20
#define MODBUS_READ_REGISTERS_CURRENT 26
#define MODBUS_READ_REGISTERS_POWER 30
#define MODBUS_READ_REGISTERS_FREQUENCY 46
#define MODBUS_READ_REGISTERS_PF 42
#define On 1

Getmodbus::Getmodbus(DeviceData *data):
//    data(new MyData),
    Data_local(data)
{
    onModbus(Data_local);
}

void Getmodbus::onModbus(DeviceData *data)
{
    uint16_t *tab_reg, *tab_reg1, *tab_reg2, *tab_reg3, *tab_reg4;
    modbus_t *ctx;
    int nb_points;
    int nb_addr, nb_addr1, nb_addr2, nb_addr3, nb_addr4;
    int rc;
    int flag = 0;

    std::cout << "Use RTU" << std::endl;
    tab_reg = (uint16_t *) malloc(MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    memset(tab_reg, 0, MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    tab_reg1 = (uint16_t *) malloc(MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    memset(tab_reg1, 0, MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    tab_reg2 = (uint16_t *) malloc(MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    memset(tab_reg2, 0, MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    tab_reg3 = (uint16_t *) malloc(MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    memset(tab_reg3, 0, MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    tab_reg4 = (uint16_t *) malloc(MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));
    memset(tab_reg4, 0, MODBUS_MAX_READ_REGISTERS * sizeof(uint16_t));

    nb_points = 1;
    nb_addr = MODBUS_READ_REGISTERS_CURRENT;
    nb_addr1 = MODBUS_READ_REGISTERS_VOLTAGE;
    nb_addr2 = MODBUS_READ_REGISTERS_POWER;
    nb_addr3 = MODBUS_READ_REGISTERS_FREQUENCY;
    nb_addr4 = MODBUS_READ_REGISTERS_PF;

    std::cout << "Writing Meter" <<std::endl;
//    ctx = modbus_new_rtu("/dev/ttyUSB0", 19200, 'N', 8, 1);
    modbus_set_slave(ctx, 1);
    std::cout << "READ REGISTERS\n\n" << std::endl;
    flag = 0;
    if (modbus_connect(ctx) == -1) {
        flag = 1;
        modbus_close(ctx);
        modbus_free(ctx);
    }

//    rc = 0;
//    sleep(1);
//    rc = modbus_read_registers(ctx, nb_addr, nb_points, tab_reg);
//    sleep(1);
//    rc = modbus_read_registers(ctx, nb_addr1, nb_points, tab_reg1);
//    sleep(1);
//    rc = modbus_read_registers(ctx, nb_addr2, nb_points, tab_reg2);
//    sleep(1);
//    rc = modbus_read_registers(ctx, nb_addr3, nb_points, tab_reg3);
//    sleep(1);
//    rc = modbus_read_registers(ctx, nb_addr4, nb_points, tab_reg4);

    if (rc == -1) {
        std::cout << "Not inserted" << std::endl;
        std::cout << "Voltage is " << -1.0f <<std::endl;
        std::cout << "Current is " << -1.0f <<std::endl;
        std::cout << "Power is " << -1.0f <<std::endl;
        std::cout << "Frequency is " << -1.0f <<std::endl;
        std::cout << "PF is " << -1.0f <<std::endl;
//        data->voltage = (-1.0f);
//        data->current = (0.467);
//        data->power = (-1.0f);
//        data->frequency = (-1.0f);
//        data->pf = (-1.0f);
//        sleep(10);
//        data->voltage = (-1.0f);
//        data->current = (0.4);
//        data->power = (-1.0f);
//        data->frequency = (-1.0f);
//        data->pf = (-1.0f);
//        sleep(10);
        data->voltage = (-1.0f);
        data->current = (-1.0f);
        data->power = (-1.0f);
        data->frequency = (-1.0f);
        data->pf = (-1.0f);

    } else{
        std::cout << "modbusread~~~~"<<std::endl;
        std::cout << "Voltage is "<< (double)*tab_reg1/10 <<std::endl;
        std::cout << "Current is "<< (double)*tab_reg*4/1000 <<std::endl;
        std::cout << "Power is "<< (double)*tab_reg2*0.4 <<std::endl;
        std::cout << "Frequency is "<< (double)*tab_reg3/100 <<std::endl;
        std::cout << "PF is "<< (double)*tab_reg4/1000 <<std::endl;

        data->id = (0);
        data->current = ((double)*tab_reg*4/1000);
        data->voltage = ((double)*(tab_reg1)/10);
        data->power = ((double)*tab_reg2*0.4);
        data->frequency = ((double)*(tab_reg3)/100);
        data->pf = ((double)*(tab_reg4)/1000);
    }
    if(data->power == -1){
        data->status = "Off";
    } else {
        data->status = "On";
    }
    std::cout<< "status is " << data->status <<std::endl;
    std::cout<< std::endl;

    if(!flag){
        modbus_close(ctx);
        modbus_free(ctx);
        free(tab_reg);
        free(tab_reg1);
        free(tab_reg2);
        free(tab_reg3);
        free(tab_reg4);
    }
}
