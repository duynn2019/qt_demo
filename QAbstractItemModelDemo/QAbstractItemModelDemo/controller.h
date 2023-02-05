#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "data.h"

class controller : public QObject
{
    Q_OBJECT
public:

    explicit controller(QObject *parent = 0);

    Q_INVOKABLE void emitData(int data);

    Q_INVOKABLE void removeData(int data);

    Q_INVOKABLE QObject *getModel() {return model;};

signals:
    void modelChanged();

private:
    dataModel *model{nullptr};


};

#endif // CONTROLLER_H
