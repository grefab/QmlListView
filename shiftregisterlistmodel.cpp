#include "shiftregisterlistmodel.h"

ShiftRegisterListModel::ShiftRegisterListModel(QObject* parent) :
    super(parent)
{
    addRoleAccessor("name", [](const ShiftRegisterElement& item)
    {
        return item.name_;
    });

    pushBack(ShiftRegisterElement("foo"));
    pushBack(ShiftRegisterElement("bar"));
    pushBack(ShiftRegisterElement("baz"));
}

void ShiftRegisterListModel::addStuff(QString stuff)
{
    pushFront(ShiftRegisterElement(stuff));
}

void ShiftRegisterListModel::killLast()
{
    popBack();
}

