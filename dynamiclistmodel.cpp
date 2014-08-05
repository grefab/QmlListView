#include "dynamiclistmodel.h"

#include <QDebug>

DynamicListModel::DynamicListModel(QObject* parent) :
    QAbstractListModel(parent)
{
    stuff_.append(DynamicListItem("foo"));
    stuff_.append(DynamicListItem("bar"));
    stuff_.append(DynamicListItem("baz"));
}

QHash<int, QByteArray> DynamicListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
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
    if( index.row() >= 0 && index.row() < stuff_.size() ) {
        switch( role ) {
            case NameRole:
                return stuff_[index.row()].name();
            default:
                return QVariant();
        }
    }

    return QVariant();
}
