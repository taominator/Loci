#include "card_model.h"

card_model::card_model(QObject *parent)
    : QObject{parent}
{

}

void card_model::setDb(QSqlDatabase &db)
{
    db2 = db;
}

void card_model::set_cardinfo(QStringList cardinfo_list)
{
    deckname = cardinfo_list.value(0);
    card_id = cardinfo_list.value(1);

    QSqlQuery query(db2);
    callSql(&query, "SELECT * FROM " + deckname + " WHERE id = " + card_id);
    qInfo() << query.first();

    QSqlRecord record = db2.record(deckname);
    int num_columns = record.count();
    for(int i = 0; i < num_columns; i++)
    {
        QString field = record.field(i).name();
        fields.append(field);

        contents.append(query.value(i).toString());
    }
}

void card_model::callSql(QSqlQuery *query, QString queryString)
{
    query->prepare(queryString);
    query->exec();
}

void card_model::test()
{
    deckname = "test2";
    card_id = "1";
    QStringList test_list {deckname, card_id};
    set_cardinfo(test_list);
    qInfo() << fields;
    qInfo() << "-------------";
    qInfo() << contents;
}
