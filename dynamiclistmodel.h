#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H

#include <QAbstractListModel>

#include <functional>

class DynamicListModelQt : public QAbstractListModel
{
    Q_OBJECT

protected:
    /* Standard constructor. We do not want to be instanciated directly. */
    DynamicListModelQt(QObject* parent = 0);

protected:
    /* Interface for DynamicListModel. */
    void push(std::function<void(void)> pushAction, int idx);
    void pop(std::function<void(void)> popAction, int idx);
    virtual QVariant itemAsVariant(int idx, const QString& role) const =0;
    virtual int count() const =0;

public:
    /* Implementation of QAbstractListModel interface. */
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

};

template <typename T>
class DynamicListModel : public DynamicListModelQt
{
public:
    /* Accessors */
    const T& at(int index) const { return items_.at(index); }

    void pushFront(const T& item) { DynamicListModelQt::push([&]() { items_.prepend(item); }, 0); }
    void pushBack(const T& item) { DynamicListModelQt::push([&]() { items_.append(item); }, items_.count() ); }
    void popFront() { DynamicListModelQt::pop([&]() { items_.removeFirst(); }, 0); }
    void popBack() { DynamicListModelQt::pop([&]() { items_.removeFirst(); }, items_.count() -1); }

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
    /* Implementation of DynamicListModelQt interface. */
    QVariant itemAsVariant(int idx, const QString& role) const {
        return accessorByRole_.contains(role) ? accessorByRole_[role](items_[idx]) : QVariant();
    }
    int count() const { return items_.count(); }

private:
    /* Our data. */
    QList<T> items_;
    QMap<QString, std::function<QVariant(const T& item)>> accessorByRole_;

};

#endif // DYNAMICLISTMODEL_H
