#include "dynamiclistmodel.h"

DynamicListModel::DynamicListModel(QObject parent) :
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
    return stuff_.count();
}

QVariant DynamicListModel::data(const QModelIndex& index, int role) const
{

}
