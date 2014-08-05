#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "dynamiclistmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyListModel myListModel;
    engine.rootContext()->setContextProperty("dynamicListModel", &myListModel);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
