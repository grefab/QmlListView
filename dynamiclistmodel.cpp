#include "dynamiclistmodel.h"

#include <QDebug>

DynamicListModelQt::DynamicListModelQt(QObject* parent) :
    QAbstractListModel(parent)
{
}

void DynamicListModelQt::push(std::function<void(void)> pushAction, int idx)
{
    beginInsertRows(QModelIndex(), idx, idx);
    pushAction();
    endInsertRows();
}

void DynamicListModelQt::pop(std::function<void(void)> popAction, int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    popAction();
    endRemoveRows();
}

int DynamicListModelQt::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return count();
}

QVariant DynamicListModelQt::data(const QModelIndex& index, int role) const
{
    if( index.row() >= 0 && index.row() < count() ) {
        return itemAt(index.row(), QString::fromUtf8(roleNames()[role]));
    }

    return QVariant();
}

MyListModel::MyListModel(QObject* parent) :
     DynamicListModel<QString>(parent)
{
    addRoleAccessor("name", [](const QString& item)
    {
        return item;
    });

    pushBack("foo");
    pushBack("bar");
    pushBack("baz");
}

void MyListModel::addStuff(QString stuff)
{
    pushFront(stuff);
}

void MyListModel::killLast()
{
    popBack();
}
