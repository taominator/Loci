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
#include <QDateTime>


class dbmanager : public QObject
{
    Q_OBJECT
public:
    explicit dbmanager(QObject *parent = nullptr);

    //Calls SQL query to set given table as model for DeckTableView
    Q_INVOKABLE void setModel(QString tablename);

    //Extracts deckname and card_id using the given index and calls card_model function to set card_info
    Q_INVOKABLE void set_cardinfo(int row_index);

    //Returns constructed SQL query for all table with columns deckname, id, Questiond and Answer for DeckTableView2
    Q_INVOKABLE QString allTableQuery(QString state);
    //with no constraints
    Q_INVOKABLE QString allTableQuery();

    //Update row
    Q_INVOKABLE void updateFieldContent(QString deckname, QString card_id, QString field, QString new_content);
    Q_INVOKABLE void updateQuestion(QString deckname, QString card_id, QString field, QString new_content);
    Q_INVOKABLE void updateAnswer(QString deckname, QString card_id, QString field, QString new_content);

    //DeckTabbleView card button functions
    Q_INVOKABLE void set_selected_table(QString my_table);
    QVariant get_next_id(QString my_table);
    Q_INVOKABLE void reload_m_model();
    Q_INVOKABLE void add_card();
    Q_INVOKABLE void remove_cards();
    Q_INVOKABLE void reset_cards();
    Q_INVOKABLE void suspend_cards();
    Q_INVOKABLE void unsuspend_cards();

    //Creating and Deleting decks
    Q_INVOKABLE void create_table(QString my_table);
    Q_INVOKABLE void drop_table(QString my_table);

    //Modifying fields
    Q_INVOKABLE void create_field(QString my_table, QString my_field);
    Q_INVOKABLE void drop_field(QString my_table, QString my_field);

signals:

public:
    QSqlDatabase m_db1;
    QSqlDatabase m_db2;
    tablemodel m_model;
    card_model m_card_model;

    QStringList m_tables;
    QStringListModel m_deckListModel;

    QString m_selected_table;
    QList<QString> m_internal_fields;

    QDateTime m_today;
    QString m_time_format;

};

#endif // DBMANAGER_H
