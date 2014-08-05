#include "mylistmodel.h"

MyListModel::MyListModel(QObject* parent) :
    super(parent)
{
    addRoleAccessor("foo", [](const MyElement& item)
    {
        return item.foo_;
    });

    addRoleAccessor("bar", [](const MyElement& item)
    {
        return item.bar_;
    });

    pushBack(MyElement("foo", 23));
    pushBack(MyElement("bar", 42));
}

void MyListModel::addStuff(QString stuff)
{
    pushFront(MyElement(stuff, 17));
}

void MyListModel::killLast()
{
    popBack();
}
