#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include "dynamiclistmodel.h"

struct MyElement
{
    MyElement(const QString& foo, int bar) : foo_(foo), bar_(bar) {}

    QString foo_;
    int bar_;
};

class MyListModel : public DynamicListModel<MyElement>
{
    Q_OBJECT
    typedef DynamicListModel<MyElement> super;

public:
    MyListModel(QObject* parent = 0);

public slots:
    void addStuff(QString stuff);
    void killLast();

};

#endif // MYLISTMODEL_H
