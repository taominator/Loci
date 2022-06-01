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
    Q_PROPERTY(int defaultColumnWidth READ getDefaultColumnWidth CONSTANT)
public:
    explicit tablemodel(QObject *parent = nullptr);

    void setQuery(QSqlQuery *query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void callSql(QString queryString);

    void generateColumnWidths();
    Q_INVOKABLE int getColumnWidth(int n);
    Q_INVOKABLE void setColumnWidth(int n, int new_width);
    int getDefaultColumnWidth();

//private :
public:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;

    QHash<int, int> m_columnWidths;
    int m_defaultColumnWidth;

signals:

};

#endif // TABLEMODEL_H
