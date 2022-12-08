#include "test.h"
#include <QDateTime>
#include <QDebug>
test::test(QObject *parent) : QObject(parent)
{
    MyStruct l_value;
    l_value.m_name1 = "a1";
    l_value.m_name2 = "a2";

    setMyStruct(l_value);


     QList<MyStruct> l_strList;
     l_strList.append(l_value);

     l_value.m_name1 = "b1";
     l_value.m_name2 = "b2";
     l_strList.append(l_value);

     setLstr(l_strList);

}

void test::handle()
{
    QTime time = QTime::currentTime();

    MyStruct l_value;
    l_value.m_name1 = QString::number(time.second());
    l_value.m_name2 = "a2";
    setMyStruct(l_value);

    strList[0].m_name1 = QString::number(time.second() + 1);
    emit lstrChanged();

    qDebug() << "Current time:" << time.second() << "Data:" << strObj.m_name1;


}
