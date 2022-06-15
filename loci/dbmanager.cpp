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

QString dbmanager::allTableQuery(QString state)
{
    QString querystring = "SELECT deckname, id, Question, Answer FROM " + m_tables.at(0) + " WHERE card_state = \"" + state + "\"";
    int num_tables = m_tables.length();

    for(int i = 1; i < num_tables; i++)
    {
        querystring += " UNION ALL SELECT deckname, id, Question, Answer FROM " + m_tables.at(i) + " WHERE card_state = \"" + state + "\"";
    }

    return querystring;
}

QString dbmanager::allTableQuery()
{
    QString querystring = "SELECT deckname, id, Question, Answer FROM " + m_tables.at(0);
    int num_tables = m_tables.length();

    for(int i = 1; i < num_tables; i++)
    {
        querystring += " UNION ALL SELECT deckname, id, Question, Answer FROM " + m_tables.at(i);
    }

    return querystring;
}

void dbmanager::updateFieldContent(QString deckname, QString card_id, QString field, QString new_content)
{
    QString querystring = "UPDATE " + deckname + " SET " + field + " = \"" + new_content + "\" WHERE id = \"" + card_id + "\"";
    m_card_model.updateDb2(querystring);
}

void dbmanager::updateQuestion(QString deckname, QString card_id, QString field, QString new_content)
{
    QString querystring = "UPDATE " + deckname + " SET " + field + " = \"" + new_content + "\" WHERE id = \"" + card_id + "\"";
    m_card_model.updateDb2(querystring);
    querystring = "UPDATE " + deckname + " SET Question = \"" + new_content + "\" WHERE id = \"" + card_id + "\"";
    m_card_model.updateDb2(querystring);
}

void dbmanager::updateAnswer(QString deckname, QString card_id, QString field, QString new_content)
{
    QString querystring = "UPDATE " + deckname + " SET " + field + " = \"" + new_content + "\" WHERE id = \"" + card_id + "\"";
    m_card_model.updateDb2(querystring);
    querystring = "UPDATE " + deckname + " SET Answer = \"" + new_content + "\" WHERE id = \"" + card_id + "\"";
    m_card_model.updateDb2(querystring);
}
