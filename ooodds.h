#ifndef OOODDS_H
#define OOODDS_H

#include <QThread>
#include <QString>
#include <QObject>
#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <dds_c/dds_c_infrastructure.h>
#include <dds_c/dds_c_domain.h>
#include "ndds/ndds_cpp.h"

enum PUB_SUB{
    DDS_SUB,
    DDS_PUB
};

enum DEVICE_CHOICE{
    DDS_METER,
    DDS_RELAY
};

typedef struct DeviceData{
    std::string status;
    int32_t id;
    float voltage;
    float current;
    float power;
    float frequency;
    float pf;
}DeviceData;

typedef struct TempData1{
    float voltage;
    float current;
    float power;
    float frequency;
    float pf;
    int32_t id;
    int32_t status;
    int32_t padding1;
    int32_t padding2;
    friend std::ostream& operator<<(std::ostream& os, const TempData1& data){
        std::cout << "voltage: " << data.voltage << std::endl;
        std::cout << "current: " << data.current << std::endl;
        std::cout << "power: " << data.power << std::endl;
        std::cout << "frequency: " << data.frequency << std::endl;
        std::cout << "pf: " << data.pf << std::endl;
        std::cout << "id: " << data.id << std::endl;
        std::cout << "status: " << data.status << std::endl;
        std::cout << "padding1: " << data.padding1 << std::endl;
        std::cout << "padding2: " << data.padding2 << std::endl;
    }
}TempData1;
class oooDDS: public QThread
{
    Q_OBJECT
public:
    explicit oooDDS(int domain, DeviceData *Data, bool pub_sub, bool choice);
    void set_count(int n){ this->count = std::abs(n);}
    void set_delay(int t){ this->delaytime = std::abs(t);}
    void set_always(bool n){ this->always = n;}
    void dds_write();
    void dds_read_relay();
    void dds_read_meter();
    void dds_destroy();
//    void Domainparticipant();  //
    void run () {
        if(pub_sub){

            this->dds_write();
        }
        else{
            if(relay_meter)
                this->dds_read_relay();
            else
                this->dds_read_meter();
        }
    }

private:
    int count;
    int running;
    bool always;
    bool pub_sub;
    bool relay_meter;
    unsigned long delaytime;
    DeviceData *Data;
    dds::domain::qos::DomainParticipantFactoryQos *dds_qos; //
    dds::domain::DomainParticipantListener *participant_listener; //
    dds::domain::DomainParticipant *dds_participant;
    dds::topic::Topic<two::Relay> *dds_relaytopic;
    dds::topic::Topic<two::Meter> *dds_metertopic;
    dds::pub::Publisher *dds_publisher;
    dds::sub::Subscriber *dds_subscriber;
    dds::pub::DataWriter<two::Relay> *dds_relaywriter;
    dds::sub::DataReader<two::Relay> *dds_relayreader;
    dds::pub::DataWriter<two::Meter> *dds_meterwriter;
    dds::sub::DataReader<two::Meter> *dds_meterreader;
    two::Relay *dds_relaysample;
    two::Meter *dds_metersample;


signals:
    void response_pub_sub(QString);
    void response_on_sub(int);
};

#endif
// OOODDS_H
