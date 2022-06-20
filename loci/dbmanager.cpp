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

    m_time_format = "dd-MM-yyyy";
    m_today = QDateTime::currentDateTime();
    //m_today = today.toString(time_format);

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

void dbmanager::set_selected_table(QString my_table)
{
    m_selected_table = my_table;
}

QVariant dbmanager::get_next_id(QString my_table)
{
    QString querystring = "Select MAX(id) from " + my_table + ";";
    QSqlQuery query(m_db1);
    query.prepare(querystring);
    query.exec();
    query.first();
    int id = query.value(0).toInt() + 1;
    return id;
}

void dbmanager::add_card()
{
    QString querystring = "INSERT INTO " + m_selected_table + " (deckname, id) VALUES (" + "\'" + m_selected_table + "\'" + ", " + get_next_id(m_selected_table).toString() + ");";
    QSqlQuery query(m_db1);
    query.prepare(querystring);
    query.exec();
}

void dbmanager::remove_cards()
{
    QString querystring;
    for(int i = 0; i < m_model.m_selectedIds.size(); i++)
    {
        QSqlQuery query(m_db1);
        querystring = "DELETE FROM " + m_selected_table + " WHERE id = " + QString::number(m_model.m_selectedIds[i]) + ";";
        query.exec(querystring);
    }
}

void dbmanager::reset_cards()
{
    QString querystring;
    for(int i = 0; i < m_model.m_selectedIds.size(); i++)
    {
        QSqlQuery query(m_db1);
        querystring = "UPDATE " + m_selected_table + " SET previous_date = 0, review_date = 0, interval = 1, ease = 2.5, card_state = 'New' WHERE id = " + QString::number(m_model.m_selectedIds[i]) + ";";
        query.exec(querystring);
    }
}

void dbmanager::suspend_cards()
{
    QString querystring;
    for(int i = 0; i < m_model.m_selectedIds.size(); i++)
    {
        QSqlQuery query(m_db1);
        querystring = "UPDATE " + m_selected_table + " SET card_state = 'Suspended' WHERE id = " + QString::number(m_model.m_selectedIds[i]) + ";";
        query.exec(querystring);
    }
}

void dbmanager::unsuspend_cards()
{
    QString querystring;
    for(int i = 0; i < m_model.m_selectedIds.size(); i++)
    {
        if(m_model.m_card_states[i] == "Suspended")
        {
            QDateTime review = m_today.addDays(m_model.m_intervals[i]);
            QString review_date = review.toString(m_time_format);

            QSqlQuery query(m_db1);
            querystring = "UPDATE " + m_selected_table + " SET previous_date = " + "'" + m_today.toString(m_time_format) + "'" + ", review_date = " + "'" + review_date + "'" + ", card_state = 'Review' WHERE id = " + QString::number(m_model.m_selectedIds[i]) + ";";
            query.exec(querystring);
            qInfo() << querystring;
        }
    }
}

void dbmanager::reload_m_model()
{
    setModel(m_selected_table);
}

void dbmanager::create_table(QString my_table)
{
    QString querystring;
    querystring += "CREATE TABLE IF NOT EXISTS " + my_table +" ( deckname TEXT, ";
    querystring += "id INTEGER, ";
    querystring += "Question TEXT DEFAULT 'question_field', ";
    querystring += "Answer TEXT DEFAULT 'answer_field', ";
    querystring += "previous_date TEXT, ";
    querystring += "review_date TEXT, ";
    querystring += "graduating_interval INTEGER, ";
    querystring += "ease REAL, ";
    querystring += "easy_bonus REAL, ";
    querystring += "interval_modifier REAL, ";
    querystring += "card_state TEXT );";

    //qInfo() << querystring;

    QSqlQuery query(m_db1);
    query.prepare(querystring);
    query.exec();

    m_tables = m_db1.tables(QSql::Tables);
    m_deckListModel.setStringList(m_tables);
}

void dbmanager::drop_table(QString my_table)
{
    QString querystring;
    querystring += "DROP TABLE IF EXISTS " + my_table + ";";

    QSqlQuery query(m_db1);
    query.prepare(querystring);
    query.exec();

    m_tables = m_db1.tables(QSql::Tables);
    m_deckListModel.setStringList(m_tables);
}
