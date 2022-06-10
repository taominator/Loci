#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlField>
#include <tablemodel.h>
#include <QStringListModel>
#include <card_model.h>

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
    void pass_cardinfo(int row_index);

signals:

public:
    QSqlDatabase m_db1;
    QSqlDatabase m_db2;
    tablemodel m_model;
    card_model m_card_model;

    QStringList m_tables;
    QStringListModel m_deckListModel;
    QList<deck> m_decklist;

};

#endif // DBMANAGER_H
