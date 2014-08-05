#include "dynamiclistmodel.h"

#include <QDebug>

DynamicListModel::DynamicListModel(QObject* parent) :
    QAbstractListModel(parent)
{
    stuff_.append(DynamicListItem("foo"));
    stuff_.append(DynamicListItem("bar"));
    stuff_.append(DynamicListItem("baz"));
}

void DynamicListModel::pushFront(QString stuff)
{
    beginInsertRows(QModelIndex(), 0, 0);
    stuff_.prepend(stuff);
    endInsertRows();
}

void DynamicListModel::pushBack(QString stuff)
{
    beginInsertRows(QModelIndex(), stuff_.size(), stuff_.size());
    stuff_.append(stuff);
    endInsertRows();
}

void DynamicListModel::popFront()
{
    if( !stuff_.isEmpty() ) {
        beginRemoveRows(QModelIndex(), 0, 0);
        stuff_.removeFirst();
        endRemoveRows();
    }
}

void DynamicListModel::popBack()
{
    if( !stuff_.isEmpty() ) {
        beginRemoveRows(QModelIndex(), stuff_.size() -1, stuff_.size() -1);
        stuff_.removeLast();
        endRemoveRows();
    }
}

void DynamicListModel::addStuff(QString stuff)
{
    pushFront(stuff);
}

void DynamicListModel::killLast()
{
    popBack();
}

QHash<int, QByteArray> DynamicListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
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
