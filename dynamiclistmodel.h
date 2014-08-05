#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H

#include <QAbstractListModel>
#include "dynamiclistitem.h"

#include <functional>

class DynamicListModelQt : public QAbstractListModel
{
    Q_OBJECT

protected:
    /* Standard constructor. */
    DynamicListModelQt(QObject* parent = 0);

protected:
    /* Used by DynamicListModel. */
    void push(std::function<void(void)> pushAction, int idx);
    void pop(std::function<void(void)> popAction, int idx);
    virtual QVariant itemAt(int idx, QString role) const =0;
    virtual int count() const =0;

public:
    /* QAbstractListModel interface. */
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

};

template <typename T>
class DynamicListModel : public DynamicListModelQt
{
protected:
    DynamicListModel(QObject* parent = 0) : DynamicListModelQt(parent) {}

public:
    /* QAbstractListModel interface. */
    QHash<int, QByteArray> roleNames() const {
        QHash<int, QByteArray> roles;
        const QStringList roleNames = accessorByRole_.keys();

        int userRoleIncrement = 0;
        for( const QString roleName : roleNames ) {
            roles[++userRoleIncrement] = roleName.toUtf8();
        }

        return roles;
    }

protected:
    /* DynamicListModelQt interface. */
    QVariant itemAt(int idx, QString role) const {
        if( accessorByRole_.contains(role) ) {
            return accessorByRole_[role](items_[idx]);
        }

        return QVariant();
    }

    int count() const { return items_.count(); }

public:
    /* Accessors */
    const T& at(int index) const { return items_.at(index); }

    void pushFront(const T& item) { DynamicListModelQt::push([&]() { items_.prepend(item); }, 0); }
    void pushBack(const T& item) { DynamicListModelQt::push([&]() { items_.append(item); }, items_.count() ); }
    void popFront() { DynamicListModelQt::pop([&]() { items_.removeFirst(); }, 0); }
    void popBack() { DynamicListModelQt::pop([&]() { items_.removeFirst(); }, items_.count() -1); }

protected:
    void addRoleAccessor(QString roleName, std::function<QVariant(const T& item)> accessor) {
        accessorByRole_.insert(roleName, accessor);
    }

private:
    QList<T> items_;
    QMap<QString, std::function<QVariant(const T& item)>> accessorByRole_;

};

class MyListModel : public DynamicListModel<QString>
{
    Q_OBJECT

public:
    MyListModel(QObject* parent = 0);

public slots:
    void addStuff(QString stuff);
    void killLast();

};
#endif // DYNAMICLISTMODEL_H
