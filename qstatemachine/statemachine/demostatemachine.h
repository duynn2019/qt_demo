#ifndef DEMOSTATEMACHINE_H
#define DEMOSTATEMACHINE_H

#include <QObject>
#include <QStateMachine>
#include <QFinalState>

class DemoStateMachine : public QObject
{
    Q_OBJECT
public:
    static DemoStateMachine& getInstance();

    Q_INVOKABLE void update();

    const QString &getColor() const;
    void setColor(const QString &newColor);

private:
    explicit DemoStateMachine(QObject *parent = nullptr);
    QStateMachine * machine{nullptr};
    QString color;

    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)

signals:
    void updateState();
    void colorChanged();

public slots:
    void enterGreenState();
    void enterYellowState();
    void enterRedState();
};

#endif // DEMOSTATEMACHINE_H
