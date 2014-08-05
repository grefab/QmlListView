#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "shiftregisterlistmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ShiftRegisterListModel shiftRegisterListModel;
    engine.rootContext()->setContextProperty("shiftRegisterListModel", &shiftRegisterListModel);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
