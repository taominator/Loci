#include "dbmanager.h"
#include <QSqlRecord>
#include <QtDebug>
#include <QStandardPaths>

dbmanager::dbmanager(QObject *parent)
    : QObject{parent}
{
    //make first database connection and send db1 to m_model
    m_db1 = QSqlDatabase::addDatabase("QSQLITE", "db1");
    m_db1.setDatabaseName(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/decks.db");
    m_db1.open();
    m_model.setDb(m_db1);
    m_tables = m_db1.tables(QSql::Tables);

    //make second database connection and send db2 to card_model
    m_db2 = QSqlDatabase::addDatabase("QSQLITE", "db2");
    m_db2.setDatabaseName(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/decks.db");
    m_db2.open();
    m_card_model.setDb(m_db2);

    QString time_format = "yyyy-MM-dd";
    QDateTime today = QDateTime::currentDateTime();
    m_today = today.toString(time_format);

    m_deckListModel.setStringList(m_tables);
}

void dbmanager::setModel(QString tablename)
{
    m_model.callSql("SELECT * FROM " + tablename);
}

void dbmanager::set_cardinfo(int row_index)
{
    QSqlQuery query = m_model.query();
    query.seek(row_index);

    QString deckname = query.value(0).toString();
    QString card_id = query.value(1).toString();

    m_card_model.set_cardinfo(deckname, card_id);
}

//SELECT * FROM test LEFT OUTER JOIN test2 ON test.card_state = test2.card_state WHERE test.card_state = "review"
//UNION ALL
//SELECT * FROM test2 LEFT OUTER JOIN test ON test.card_state = test2.card_state WHERE test2.card_state = "review"


void dbmanager::createAllView()
{
    int num_decks = m_tables.length();
    QString querystring;

    if(num_decks == 1)
    {
        querystring = "CREATE TEMP VIEW allview AS SELECT deckname, id, Question, Answer FROM " + m_tables.at(0);
    }
    else
    {

    }
    m_model.callSql(querystring);
}

QString dbmanager::getFullJoinString(QString state)
{
    QString querystring = "DROP VIEW allview ";
    int num_tables = m_tables.length();
    QString first_table = m_tables.at(0);

    for(int i = 1; i < num_tables; i++)
    {
        querystring += " FULL JOIN " + m_tables.at(i) + " ON " + first_table + ".deckname = " + m_tables.at(i) + ".deckname";
    }

    return querystring;
}
