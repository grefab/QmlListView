#ifndef DYNAMICLISTITEM_H
#define DYNAMICLISTITEM_H

#include <QMetaType>
#include <QAbstractListModel>

class DynamicListItem
{
public:
    DynamicListItem();
    DynamicListItem(const QString& name);
    DynamicListItem(const DynamicListItem& other);
    ~DynamicListItem();

    QString name() const;
    void setName(const QString& name);

private:
    QString name_;

};

Q_DECLARE_METATYPE(DynamicListItem)

#endif // DYNAMICLISTITEM_H
