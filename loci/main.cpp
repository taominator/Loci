#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <filereader.h>
#include <QQmlContext>
//#include <appfunctions.h>
//#include <selectedcard.h>
//#include <cardmodel.h>
#include <dbmanager.h>
#include <QDebug>
#include <QScreen>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /*deck* deck1 = new deck;
    deck1->setParent(&app);
    cardmodel* cardModel = new cardmodel;
    cardModel->setParent(&app);

    readFiles(deck1);*/


    dbmanager DBManager;

    int screenWidth = app.primaryScreen()->size().width();
    // 5.0 to prevent truncation of integer
    int tableSize = screenWidth*(4/5.0) - (DBManager.m_model.m_borderWidth*2); //10 for scrollbar width

    DBManager.m_model.setTableWidth(tableSize);
    DBManager.setModel("test2");


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/loci/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    /*card* card1 = deck1->getCardList().at(0);
    cardModel->setSelectedCard(deck1, card1);

    engine.rootContext()->setContextProperty("deck", deck1);
    engine.rootContext()->setContextProperty("cardmodel", cardModel);*/
    engine.rootContext()->setContextProperty("dbmanager", &DBManager);
    engine.rootContext()->setContextProperty("m_model", &DBManager.m_model);
    engine.rootContext()->setContextProperty("m_deckListModel", &DBManager.m_deckListModel);

    engine.load(url);


    /*qInfo() << DBManager.m_model.record();
    qInfo() << DBManager.m_db.isOpen();
    qInfo() << DBManager.m_decklist.at(1).m_table;
    qInfo() << "---------";
    qInfo() << DBManager.m_decklist.at(0).m_fields;
    qInfo() << DBManager.m_decklist.at(1).m_fields;
    qInfo() << "---------";
    qInfo() << DBManager.m_model.m_roleNames;
    qInfo() << "---------";
    qInfo() << DBManager.m_model.m_columnWidths;
    qInfo() << DBManager.m_model.m_columnWidths;
    qInfo() << app.primaryScreen()->size().width();*/

    return app.exec();
}
