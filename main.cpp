#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "mylistmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyListModel myListModel;
    engine.rootContext()->setContextProperty("myListModel", &myListModel);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
