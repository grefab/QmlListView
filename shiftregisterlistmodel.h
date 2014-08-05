#ifndef SHIFTREGISTERLISTMODEL_H
#define SHIFTREGISTERLISTMODEL_H

#include "dynamiclistmodel.h"
#include "shiftregisterelement.h"

class ShiftRegisterListModel : public DynamicListModel<ShiftRegisterElement>
{
    Q_OBJECT

    typedef DynamicListModel<ShiftRegisterElement> super;

public:
    ShiftRegisterListModel(QObject* parent = 0);

public slots:
    void addStuff(QString stuff);
    void killLast();

};

#endif // SHIFTREGISTERLISTMODEL_H
