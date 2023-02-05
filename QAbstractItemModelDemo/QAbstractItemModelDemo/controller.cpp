#include "controller.h"
#include <QDebug>

controller::controller(QObject *parent) : QObject(parent)
{
    model = new dataModel();
}

void controller::emitData(int data)
{
    qDebug() << "Controller emitData" << data;


    model->emitData(data);
}

void controller::removeData(int data)
{
    qDebug() << "Controller removeData" << data;
    model->removeData(data);
}
