#include "dynamiclistitem.h"

DynamicListItem::DynamicListItem(const QString& name) :
    name_(name)
{
}

QString DynamicListItem::name() const
{
    return name_;
}

void DynamicListItem::setName(const QString& name)
{
    name_ = name;
}

