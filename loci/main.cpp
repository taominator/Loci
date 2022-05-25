#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <filereader.h>
#include <QQmlContext>
#include <appfunctions.h>
#include <selectedcard.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    deck* deck1 = new deck;
    selectedcard* selectedCard = new selectedcard;

    readFiles(deck1);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/loci/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    card* card1 = deck1->getCardList()[0];
    selectedCard->setSelectedCardPointer(card1);

    engine.rootContext()->setContextProperty("deck", deck1);
    engine.rootContext()->setContextProperty("selectedCard", selectedCard);

    engine.load(url);

    delete deck1;
    delete selectedCard;
    return app.exec();
}
