#ifndef TEST_H
#define TEST_H

#include <QObject>

struct MyStruct {
    Q_GADGET
   // Q_OBJECT
    int m_val;

public:
    QString m_name1;
    QString m_name2;
    QString m_name3;
    QString m_name4;
    Q_PROPERTY(int val MEMBER m_val)
    Q_PROPERTY(QString name1 MEMBER m_name1)
    Q_PROPERTY(QString name2 MEMBER m_name2)
    Q_PROPERTY(QString name3 MEMBER m_name3)
    Q_PROPERTY(QString name4 MEMBER m_name4)
};

Q_DECLARE_METATYPE(MyStruct);

class test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MyStruct mystr READ getMyStruct
               WRITE setMyStruct NOTIFY myStructChanged)

    Q_PROPERTY(QList<MyStruct> lstr READ getLstr
               WRITE setLstr NOTIFY lstrChanged)

public:
    explicit test(QObject *parent = nullptr);


    MyStruct strObj;

    MyStruct getMyStruct() const
    {
        return strObj;
    }

    Q_INVOKABLE void handle();

    void setMyStruct(MyStruct val)
    {
        strObj = val;
        emit myStructChanged();
    }

    QList<MyStruct> strList;

    QList<MyStruct>  getLstr() const
    {
        return strList;
    }

    void setLstr(QList<MyStruct> val)
    {
        strList = val;
        emit lstrChanged();
    }



signals:
    void myStructChanged();
    void lstrChanged();

public slots:

};

#endif // TEST_H
