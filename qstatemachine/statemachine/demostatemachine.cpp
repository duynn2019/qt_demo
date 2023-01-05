#include "demostatemachine.h"
#include <QDebug>

DemoStateMachine::DemoStateMachine(QObject *parent)
    : QObject{parent}
{

    color = "green";

    machine = new QStateMachine();
    auto greenState = new QState();
    auto yellowState = new QState();
    auto redState = new QState();

    machine->addState( yellowState );
    machine->addState( redState );
    machine->addState(greenState );
    machine->setInitialState( greenState );

    greenState->addTransition(this, SIGNAL(updateState()), yellowState);
    yellowState->addTransition(this, SIGNAL(updateState()), redState);
    redState->addTransition(this, SIGNAL(updateState()), greenState);

    connect( greenState, &QState::entered, this, &DemoStateMachine::enterGreenState );
    connect( yellowState, &QState::entered, this, &DemoStateMachine::enterYellowState );
    connect( redState, &QState::entered, this, &DemoStateMachine::enterRedState );

    machine->start();
}

DemoStateMachine &DemoStateMachine::getInstance()
{
    static DemoStateMachine instance;
    return instance;
}

void DemoStateMachine::update()
{
    qDebug() << "Update State Machine";
    emit updateState();
}

const QString &DemoStateMachine::getColor() const
{
    return color;
}

void DemoStateMachine::setColor(const QString &newColor)
{
    if (color == newColor)
        return;
    color = newColor;
    emit colorChanged();
}

void DemoStateMachine::enterGreenState()
{
    qDebug() << "Goto enterGreenState";
    setColor("green");
}

void DemoStateMachine::enterYellowState()
{
    qDebug() << "Goto enterYellowState";
    setColor("yellow");
}

void DemoStateMachine::enterRedState()
{
    qDebug() << "Goto enterRedState";
    setColor("red");
}
