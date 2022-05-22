#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <filereader.h>
#include <QQmlContext>
#include <appfunctions.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    deck* deck1 = new deck;

    readFiles(deck1);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/loci/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("deck", deck1);

    engine.load(url);
    return app.exec();
}
