#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>

class card_model : public QObject
{
    Q_OBJECT
public:
    explicit card_model(QObject *parent = nullptr);

    void setDb(QSqlDatabase &db);
    void set_cardinfo(QStringList cardinfo_list);
    Q_INVOKABLE void callSql(QSqlQuery *query, QString queryString);

    void test();
signals:

public:
    QSqlDatabase db2;

    QString deckname;
    QString card_id;
    QStringList fields;
    QStringList contents;

};

#endif // CARD_MODEL_H
