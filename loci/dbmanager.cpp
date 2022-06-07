#include "dbmanager.h"
#include <QSqlRecord>
#include <QtDebug>

dbmanager::dbmanager(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/taosif/Desktop/SQLITE Databases/test.db");
    m_db.open();
    m_tables = m_db.tables(QSql::Tables);

    //populated m_decklist using each table
    foreach(QString table, m_tables )
    {
        QSqlRecord field_record = m_db.record(table);
        int count = field_record.count();
        deck deck1;
        for(int i = 0; i<count; i++)
        {
            QString field = field_record.field(i).name();
            deck1.m_fields.append(field);
        }
        deck1.m_table = table;
        m_decklist.append(deck1);
    }
    m_deckListModel.setStringList(m_tables);
}

void dbmanager::setModel(QString tablename)
{
    m_model.callSql("SELECT * FROM " + tablename);
}
