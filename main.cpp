#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "dynamiclistmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    DynamicListModel dynamicListModel;
    engine.rootContext()->setContextProperty("dynamicListModel", &dynamicListModel);

    return app.exec();
}
