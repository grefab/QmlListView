#ifndef DYNAMICLISTITEM_H
#define DYNAMICLISTITEM_H

#include <QMetaType>
#include <QAbstractListModel>

class DynamicListItem
{
public:
    DynamicListItem(const QString& name);

    QString name() const;
    void setName(const QString& name);

private:
    QString name_;

};

#endif // DYNAMICLISTITEM_H
