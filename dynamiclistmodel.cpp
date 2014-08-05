#include "dynamiclistmodel.h"

#include <QDebug>

DynamicListModel::DynamicListModel(QObject* parent) :
    QAbstractListModel(parent)
{
}

void DynamicListModel::enqueueStuff(QString stuff)
{
    stuff_ << stuff;
}

void DynamicListModel::dequeueStuff()
{
    if( !stuff_.isEmpty() ) {
        stuff_.removeFirst();
    }
}

int DynamicListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return stuff_.count();
}

QVariant DynamicListModel::data(const QModelIndex& index, int role) const
{
    qDebug() << role;

    if( index.row() >= 0 && index.row() < stuff_.size() ) {
        return QVariant(stuff_[index.row()]);
    }

    return QVariant();
}
