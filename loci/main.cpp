#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <filereader.h>
#include <QQmlContext>
#include <appfunctions.h>
#include <selectedcard.h>
#include <cardmodel.h>
#include <dbmanager.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    deck* deck1 = new deck;
    deck1->setParent(&app);
    cardmodel* cardModel = new cardmodel;
    cardModel->setParent(&app);

    readFiles(deck1);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/loci/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    card* card1 = deck1->getCardList().at(0);
    cardModel->setSelectedCard(deck1, card1);

    engine.rootContext()->setContextProperty("deck", deck1);
    engine.rootContext()->setContextProperty("cardmodel", cardModel);

    engine.load(url);

    dbmanager DBManager;

    qInfo() << DBManager.m_tables;

    return app.exec();
}
