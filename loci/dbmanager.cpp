#include "dbmanager.h"

dbmanager::dbmanager(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/taosif/Desktop/SQLITE Databases/test.db");
    m_db.open();
    m_tables = m_db.tables(QSql::Tables);
}
