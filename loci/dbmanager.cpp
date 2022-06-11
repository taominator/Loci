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

    //populated m_decklist using each table
    /*foreach(QString table, m_tables )
    {
        QSqlRecord field_record = m_db1.record(table);
        int count = field_record.count();
        deck deck1;
        for(int i = 0; i<count; i++)
        {
            QString field = field_record.field(i).name();
            deck1.m_fields.append(field);
        }
        deck1.m_table = table;
        m_decklist.append(deck1);
    }*/
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
