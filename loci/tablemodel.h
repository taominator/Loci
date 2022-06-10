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

    //Overwritten tableView functions
    void setQuery(QSqlQuery *query);
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE void callSql(QString queryString);


    void setDb(QSqlDatabase &db);
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

    Q_INVOKABLE bool containsRow(int index);
    Q_INVOKABLE QString colorProvider(int index);
    Q_INVOKABLE void leftClick(int index);
    Q_INVOKABLE void ctrlClick(int index);
    Q_INVOKABLE void shiftClick(int index);
    Q_INVOKABLE void ctrlAll(int num_rows);

public:
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;

    QSqlDatabase db1;
    QHash<int, int> m_columnWidths;
    int m_defaultColumnWidth;
    int m_borderWidth = 20;
    int m_tableWidth;
    int m_sumColumnWidths;

    QList<int> m_selectedRows;

signals:

};

#endif // TABLEMODEL_H
