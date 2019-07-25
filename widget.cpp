#include "ooodds.h"
#include <iostream>
#include <QObject>
#include <QLCDNumber>
#include "widget.h"

Widget::Widget(QWidget *parent, MyData *data_para) :
    QWidget(parent),data(data_para)
{
    setWindowTitle(tr("按鍵組"));
    myLCDNumber = new QLCDNumber(this);
    myLCDNumber->setPalette(Qt::black);    //設定顏色
    myLCDNumber->setDigitCount(6);         //設定位數
    myLCDNumber->display(244.52);          //設定顯示數字
    myLCDNumber->setGeometry(30,30,80,30); //設定位置大小
}
