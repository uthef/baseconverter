#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "baseconverter.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qDebug() << BaseConverter::transform("230", BaseConverter::HEX, BaseConverter::DEC);

    MainWindow mainWindow;
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/baseconverter/Main.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );

    engine.rootContext()->setContextProperty("window", &mainWindow);
    engine.load(url);


    return app.exec();
}
