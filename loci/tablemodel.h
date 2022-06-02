#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
#include <QDebug>

class tablemodel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(int defaultColumnWidth READ getDefaultColumnWidth CONSTANT)
    Q_PROPERTY(int borderWidth READ getBorderWidth CONSTANT)

public:
    explicit tablemodel(QObject *parent = nullptr);

    void setQuery(QSqlQuery *query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void callSql(QString queryString);

    void generateColumnWidths();
    Q_INVOKABLE int getColumnWidth(int n);
    Q_INVOKABLE void setColumnWidth(int n, int new_width);    
    Q_INVOKABLE int getDefaultColumnWidth();
    Q_INVOKABLE void setTableWidth(int width);
    Q_INVOKABLE int getBorderWidth();
    Q_INVOKABLE void updateSumColumnWidths();
    Q_INVOKABLE void rectifyLastColumnWidth();
    Q_INVOKABLE int lastColumnWidth();
    Q_INVOKABLE bool tooSmallTable();


public:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;

    QHash<int, int> m_columnWidths;
    int m_defaultColumnWidth;
    int m_borderWidth = 20;
    int m_tableWidth;
    int m_sumColumnWidths;

signals:

};

#endif // TABLEMODEL_H
