#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H

#include <QAbstractListModel>

#include <functional>

class DynamicListModelQt : public QAbstractListModel
{
    Q_OBJECT

protected:
    /* Standard constructor. We do not want to be instanciated directly. */
    DynamicListModelQt(QObject* parent = 0) : QAbstractListModel(parent) {}

};

template <typename T>
class DynamicListModel : public DynamicListModelQt
{
public:
    /* Accessors */
    const T& at(int index) const { return items_.at(index); }

    void pushFront(const T& item) { push([&]() { items_.prepend(item); }, 0); }
    void pushBack(const T& item) { push([&]() { items_.append(item); }, items_.count() ); }
    void popFront() { pop([&]() { items_.removeFirst(); }, 0); }
    void popBack() { pop([&]() { items_.removeFirst(); }, items_.count() -1); }

protected:
    /* Interface for our subclasses. */
    void addRoleAccessor(QString roleName, std::function<QVariant(const T& item)> accessor) {
        accessorByRole_.insert(roleName, accessor);
    }

protected:
    /* Standard constructor. We do not want to be instanciated directly. */
    DynamicListModel(QObject* parent = 0) : DynamicListModelQt(parent) {}

public:
    /* Implementation of QAbstractListModel interface. */
    QHash<int, QByteArray> roleNames() const
    {
        QHash<int, QByteArray> roles;
        const QStringList roleNames = accessorByRole_.keys();

        int userRoleIncrement = 0;
        for( const QString roleName : roleNames ) {
            roles[++userRoleIncrement + Qt::UserRole] = roleName.toUtf8();
        }

        return roles;
    }

    int rowCount(const QModelIndex& parent) const
    {
        Q_UNUSED(parent)
        return items_.count();
    }

    QVariant data(const QModelIndex& index, int role) const
    {
        return index.row() >= 0 && index.row() < items_.count()
                ? itemAsVariant(index.row(), QString::fromUtf8(roleNames()[role]))
                : QVariant();
    }

private:
    /* Our data. */
    QList<T> items_;
    QMap<QString, std::function<QVariant(const T& item)>> accessorByRole_;

    /* Our helper methods. */
    QVariant itemAsVariant(int idx, const QString& role) const
    {
        return accessorByRole_.contains(role) ? accessorByRole_[role](items_[idx]) : QVariant();
    }

    void push(std::function<void(void)> pushAction, int idx)
    {
        beginInsertRows(QModelIndex(), idx, idx);
        pushAction();
        endInsertRows();
    }

    void pop(std::function<void(void)> popAction, int idx)
    {
        beginRemoveRows(QModelIndex(), idx, idx);
        popAction();
        endRemoveRows();
    }

};

#endif // DYNAMICLISTMODEL_H
