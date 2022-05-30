#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>

class dbmanager : public QObject
{
    Q_OBJECT
public:
    explicit dbmanager(QObject *parent = nullptr);

signals:

public:
    QSqlDatabase m_db;
    QSqlQueryModel m_model;
    QStringList m_tables;
};

#endif // DBMANAGER_H
