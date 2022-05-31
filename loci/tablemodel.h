#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>

class tablemodel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit tablemodel(QObject *parent = nullptr);

    void setQuery(QSqlQuery *query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void callSql(QString queryString);

private :
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;


signals:

};

#endif // TABLEMODEL_H
