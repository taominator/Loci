#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>

//data struct for QList m_data
struct Data
{
    Data(QString field, QString content) : field(field), content(content) {}

    QString field;
    QString content;
};


class card_model : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit card_model(QObject *parent = nullptr);

    //Listmodel overwriten functions
    enum Roles {
        FieldRole = Qt::UserRole, ContentRole
    };
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    //database functions
    void setDb(QSqlDatabase &db);
    void set_cardinfo(QString deckname, QString card_id);
    Q_INVOKABLE void callSql(QSqlQuery *query, QString queryString);

    void test();

signals:

public:
    QSqlDatabase db2;

    QString m_deckname;
    QString m_card_id;
    QStringList fields;
    QStringList contents;

    //data for listmodel
    QList<Data> m_data;
};

#endif // CARD_MODEL_H
