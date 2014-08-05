#include "dynamiclistitem.h"

DynamicListItem::DynamicListItem() :
    DynamicListItem("")
{
}

DynamicListItem::DynamicListItem(const QString& name) :
    name_(name)
{
}

DynamicListItem::DynamicListItem(const DynamicListItem& other)
{
    name_ = other.name_;
}

DynamicListItem::~DynamicListItem()
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

