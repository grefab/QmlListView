#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H

#include <QAbstractListModel>


class DynamicListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    DynamicListModel(QObject* parent = 0);

    void enqueueStuff(QString stuff);
    void dequeueStuff();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QList<QString> stuff_;
};

#endif // DYNAMICLISTMODEL_H
