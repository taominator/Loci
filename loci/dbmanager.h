#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlField>
#include <tablemodel.h>

struct deck
{
    QString m_table;
    QList<QString> m_fields;
    int field_count;
};

class dbmanager : public QObject
{
    Q_OBJECT
public:
    explicit dbmanager(QObject *parent = nullptr);

    Q_INVOKABLE void setModel(QString tablename);

signals:

public:
    QSqlDatabase m_db;
    tablemodel m_model;
    QStringList m_tables;
    QList<deck> m_decklist;
};

#endif // DBMANAGER_H
