#include "data.h"
#include <QDebug>

dataModel::dataModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int dataModel::rowCount(const QModelIndex &parent) const
{
    return model.size();
}

QVariant dataModel::data(const QModelIndex &index, int role) const
{
    int i = index.row();
    if (i < 0 || i >= model.size()) {
        return QVariant();
    }

    if (role == path) {
        return model[i].path;
    }
    if (role== dataInt) {
        return model[i].dataInt;
    }
    return QVariant();
}

QHash<int, QByteArray> dataModel::roleNames() const
{
    QHash<int, QByteArray> r =QAbstractListModel::roleNames();
    r[name]="name";
    r[path]="path";
    r[dataInt]="dataInt";
    return r;
}

void dataModel::emitData(int data)
{
    qDebug() << "Model emitData" << data;

    ModelItem item;
    item.dataInt = data;

    for (int i = 0; i< model.size(); i++)
    {
        if (data < model.at(i).dataInt)
        {
            beginInsertRows(QModelIndex(), i, i);
            model.insert(i, item);
            endInsertRows();
            return;
        }
    }

    const int line = rowCount();
    beginInsertRows(QModelIndex(), line, line);
    model.append(item);
    endInsertRows();

}

void dataModel::removeData(int data)
{
    qDebug() << "Model removeData" << data;

    for (int i = 0; i< model.size(); i++)
    {
        if (data == model.at(i).dataInt)
        {
            beginRemoveRows(QModelIndex(), i, i);
            model.remove(i);
            endRemoveRows();
            return;
        }
    }
}
