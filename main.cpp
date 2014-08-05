#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "dynamiclistmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    DynamicListModel dynamicListModel;
    engine.rootContext()->setContextProperty("dynamicListModel", &dynamicListModel);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
