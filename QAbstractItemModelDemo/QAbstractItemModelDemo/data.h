#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QAbstractListModel>
#include <QVector>

class dataModel : public QAbstractListModel
{
    Q_OBJECT

    struct ModelItem {
        QString path;
        int dataInt;

    };
    enum {name=Qt::UserRole+1, path, dataInt};

public:
    explicit dataModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;



    void emitData(int data);
    void removeData(int data);

signals:



private:
    QVector<ModelItem> model;
};

#endif // DATA_H
