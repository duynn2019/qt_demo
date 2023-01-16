#include "data.h"



Model::Model(QObject *parent) :
    QAbstractListModel(parent)
{
    CreateDefaultModel();
}

void Model::CreateDefaultModel(void)
{
    ModelItem itm;
    itm.sName = "Vitaly";
    itm.nAge = 34;
    itm.sAddr = "pics/qtlogo.png";
    itm.sPhone = "+7-909-678-67-89";
    v.push_back(itm);

    itm.sName = "Irina";
    itm.nAge = 33;
    itm.sAddr = "pics/qtlogo.png";
    itm.sPhone = "+7-909-123-45-67";
    v.push_back(itm);

    itm.sName = "Olga";
    itm.nAge = 55;
    itm.sAddr = "pics/qtlogo.png";
    itm.sPhone = "+7-909-333-55-66";
    v.push_back(itm);

    itm.sName = "Deni";
    itm.nAge = 34;
    itm.sAddr = "pics/qtlogo.png";
    itm.sPhone = "+7-909-333-77-88";
    v.push_back(itm);

//    for (int a=0; a < 100; ++a) {
//        itm.sName = "Name "+QString::number(a);
//        itm.nAge = a+5;
//        itm.sAddr = "";
//        itm.sPhone = "";
//        itm.sNote = "";
//        v.push_back(itm);
//    }
}

int Model::rowCount(const QModelIndex &parent) const
{
    return v.size();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    int i = index.row();
    if (i < 0 || i >= v.size()) {
        return QVariant();
    }

    if (role == name) {
        return v[i].sName;
    }
    if (role==age) {
        return v[i].nAge;
    }
    if (role==icon) {
        return v[i].sAddr;
    }
    if (role==phone) {
        return v[i].sPhone;
    }
    if (role==note) {
        return v[i].sNote;
    }
    if (role==Qt::DisplayRole) {
        return v[i].sName + " ("+ QString::number(v[i].nAge) +")";
    }
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> r =QAbstractListModel::roleNames();
    r[name]="name";
    r[age]="age";
    r[icon]="icon";
    r[phone]="phone";
    r[note]="note";
    return r;
}
