#ifndef MAINWINDOW_DDS_H
#define MAINWINDOW_DDS_H

#include <QMainWindow>
#include "ooodds.h"
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QListWidget>
#include "qlistwidget.h"
#include <QLCDNumber>
#include <QtWidgets>
#include "meter_relay.hpp"

struct MyData{
   std::string status;
   long id;
   float voltage;
   float current;
   float power;
   float frequency;
   float pf;
};

namespace Ui {
class MainWindow_dds;
}

class MainWindow_dds : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_dds(QWidget *parent = nullptr);
    ~MainWindow_dds();

private:
    void UISetup();
    void closeEvent(QCloseEvent *event);

public slots:
    void onTimeDisplay();

private:
    void lcdshow();

private:
    Ui::MainWindow_dds *ui;
    QTimer *timer;
    QPushButton *button;
    DeviceData Data_pub;
    DeviceData Data_sub;
    DeviceData *Data_local;
    DeviceData *Data_remote;
    DeviceData *Data_remote2;
    oooDDS *DDS_pub;
    oooDDS *DDS_sub;
    oooDDS *DDS_sub2;
    MyData *data;
    QLCDNumber *lcdNumber_vol;
    QLCDNumber *lcdNumber_cur;
    QLCDNumber *lcdNumber_p;
    QLCDNumber *lcdNumber_freq;
    QLCDNumber *lcdNumber_pf;
    QLCDNumber *lcdNumber_vol_2;
    QLCDNumber *lcdNumber_cur_2;
    QLCDNumber *lcdNumber_p_2;
    QLCDNumber *lcdNumber_freq_2;
    QLCDNumber *lcdNumber_pf_2;

signals:
    void valueChanged(float value);
};

#endif // MAINWINDOW_DDS_H
