#include "mainwindow_dds.h"
#include "ui_mainwindow_dds.h"

#include <QObject>
#include <iostream>
#include "ooodds.h"
#include "meter_relay.hpp"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <unistd.h>
#include <errno.h>
#include <QPixmap>
#include <QtXml/QtXml>
#include <QFile>
#include <QThread>
#include "get_modbus.h"

//#define G_MSEC_PER_SEC 1000
//#define MODBUS_READ_REGISTERS_VOLTAGE 20
//#define MODBUS_READ_REGISTERS_CURRENT 26
//#define MODBUS_READ_REGISTERS_POWER 30
//#define MODBUS_READ_REGISTERS_FREQUENCY 46
//#define MODBUS_READ_REGISTERS_PF 42
//#define on 1

MainWindow_dds::MainWindow_dds(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_dds),
    timer(new QTimer),
    Data_local(new DeviceData),
    Data_remote(new DeviceData),
    Data_remote2(new DeviceData),
    DDS_pub(new oooDDS(0, Data_local, DDS_PUB, 0)), //0->pub_meter
    DDS_sub(new oooDDS(0, Data_remote, DDS_SUB, 0)), //0->dds_read_meter
    DDS_sub2(new oooDDS(0, Data_remote2, DDS_SUB, 1)) //1->dds_read_relay
//    data(new MyData)
//    data2(new MyData)
{
    ui->setupUi(this);
    UISetup();
    this->Data_pub.id = 3;
    //this->Data_pub.status = "on";
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeDisplay()));
    timer->start(10);

    Get_modbus *get_modbus = new Get_modbus(this, Data_local);
    get_modbus->start();

    connect(this->DDS_pub, SIGNAL(response_pub_sub(QString)), this->ui->textEdit, SLOT(setText(QString)));
    connect(this->DDS_sub2, SIGNAL(response_pub_sub(QString)), this->ui->label, SLOT(setText(QString)));
    DDS_pub->set_always(true);
    DDS_sub->set_always(true);
    DDS_sub2->set_always(true);
    DDS_pub->set_count(2);
    DDS_sub->set_count(2);
    DDS_sub2->set_count(2);
    DDS_pub->start();
    DDS_sub->start();
    DDS_sub2->start();
    ui->lcdNumber_vol->display(0);
    ui->lcdNumber_cur->display(0);
    ui->lcdNumber_p->display(0);
    ui->lcdNumber_freq->display(0);
    ui->lcdNumber_pf->display(0);
    ui->lcdNumber_vol_2->display(0);
    ui->lcdNumber_cur_2->display(0);
    ui->lcdNumber_p_2->display(0);
    ui->lcdNumber_freq_2->display(0);
    ui->lcdNumber_pf_2->display(0);
    QDomDocument doc;
    QFile file("/home/iclab/rti_workspace/5.3.1/examples/connext_dds/qos/reliable.xml");
    if (!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Failed to open file" <<std::endl;
    }
    else {
        if(!doc.setContent(&file))
        {
            std::cout << "Failed to load doc" <<std::endl;
        }
        file.close();
    }
}

MainWindow_dds::~MainWindow_dds()
{
    delete ui;
}

void MainWindow_dds::UISetup()
{
    this->setStyleSheet("background-color:#bdd7ee");
    QPixmap pix("/home/iclab/Qtdds_0624M2/logo.png");
    ui->image->setPixmap(pix);
    ui->image->setScaledContents(true);
    ui->image->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void MainWindow_dds::lcdshow()
{
    ui->lcdNumber_vol->setDigitCount(5);
    ui->lcdNumber_cur->setDigitCount(5);
    ui->lcdNumber_p->setDigitCount(5);
    ui->lcdNumber_freq->setDigitCount(5);
    ui->lcdNumber_pf->setDigitCount(5);
    ui->lcdNumber_vol_2->setDigitCount(5);
    ui->lcdNumber_cur_2->setDigitCount(5);
    ui->lcdNumber_p_2->setDigitCount(5);
    ui->lcdNumber_freq_2->setDigitCount(5);
    ui->lcdNumber_pf_2->setDigitCount(5);
    ui->lcdNumber_vol_2->display(Data_local->voltage);
    ui->lcdNumber_cur_2->display(Data_local->current);
    ui->lcdNumber_p_2->display(Data_local->power);
    ui->lcdNumber_freq_2->display(Data_local->frequency);
    ui->lcdNumber_pf_2->display(Data_local->pf);
    ui->lcdNumber_vol->display(Data_remote->voltage);
    ui->lcdNumber_cur->display(Data_remote->current);
    ui->lcdNumber_p->display(Data_remote->power);
    ui->lcdNumber_freq->display(Data_remote->frequency);
    ui->lcdNumber_pf->display(Data_remote->pf);
//    ui->lcdNumber_vol_2->display(110);
//    ui->lcdNumber_cur_2->display(0.45);
//    ui->lcdNumber_p_2->display(10);
//    ui->lcdNumber_freq_2->display(60);
//    ui->lcdNumber_pf_2->display(0.6);
}

void MainWindow_dds::onTimeDisplay()
{
    QTime time = QTime::currentTime();
    ui->datatime->setText(time.toString());
    lcdshow();
}

void MainWindow_dds::closeEvent(QCloseEvent *event)
{
    switch(QMessageBox::information(this, tr("DDS-based Monitoring System"),
    tr("Do you really want to exit DDS?"),
    tr("Yes"), tr("No"),
    nullptr, 1 ) )
    {
     case 0:
    {
        event->accept();
        break;
    }
     case 1:
     default:
        event->ignore();
        break;
    }
}
