#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H

#include <QAbstractListModel>
#include "dynamiclistitem.h"

class DynamicListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    /* Defines the accessable elements within our model. */
    enum AnimalRoles {
        NameRole = Qt::UserRole + 1
    };

public:
    DynamicListModel(QObject* parent = 0);

    /* Our methods. */
    void enqueueStuff(QString stuff);
    void dequeueStuff();

public:
    /* QAbstractListModel interface. */
    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QList<DynamicListItem> stuff_;
};

#endif // DYNAMICLISTMODEL_H
