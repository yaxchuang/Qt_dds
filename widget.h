#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
//#include <QtWidgets>
#include <QLCDNumber>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr, MyData *data_para = nullptr);

private:
    QLCDNumber *myLCDNumber;
    MyData *data;
};

#endif // QLCDNUMBER_H
