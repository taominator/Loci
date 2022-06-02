#include "tablemodel.h"

tablemodel::tablemodel(QObject *parent)
    : QSqlQueryModel{parent}
{
    m_defaultColumnWidth = 100;
}

void tablemodel::setQuery( QSqlQuery *query)
{
    QSqlQueryModel::setQuery(std::move(*query));
    generateRoleNames();
}

QVariant tablemodel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

QHash<int, QByteArray> tablemodel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Qt::DisplayRole] = "display";
    for (int i = 0; i < this->record().count(); i++)
    {
        roles[Qt::DisplayRole + i + 1] = this->record().fieldName(i).toLocal8Bit();
    }

    return roles;
}

void tablemodel::callSql(QString queryString)
{
    QSqlQuery qry(queryString);
    this->setQuery(&qry);
    generateColumnWidths();
}

void tablemodel::generateRoleNames()
{
    m_roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        m_roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
}

void tablemodel::generateColumnWidths()
{
    for(int i = 0; i < record().count(); i ++){
        m_columnWidths[i] = m_defaultColumnWidth;
    }
    m_sumColumnWidths = record().count() * m_defaultColumnWidth;
    correctLastColumnWidth();
    //m_tableWidth = 1000;
    /*if(m_tableWidth > m_sumColumnWidths){
        m_columnWidths.insert(record().count()-1 , m_tableWidth - (m_sumColumnWidths - m_defaultColumnWidth));
        m_sumColumnWidths += m_columnWidths.value(record().count()-1) - m_defaultColumnWidth;
        qInfo() << m_sumColumnWidths;
    }*/
}

int tablemodel::getColumnWidth(int n){
    return m_columnWidths.value(n);
}

void tablemodel::setColumnWidth(int n, int new_width)
{
    m_columnWidths.insert(n, new_width);
}

int tablemodel::getDefaultColumnWidth()
{
    return m_defaultColumnWidth;
}

void tablemodel::setTableWidth(int width)
{
    m_tableWidth = width;
}

int tablemodel::getBorderWidth()
{
    return m_borderWidth;
}

void tablemodel::updateSumColumnWidths(int num)
{
    m_sumColumnWidths += num;
}

void tablemodel::correctLastColumnWidth()
{
    if(m_tableWidth > m_sumColumnWidths){
        int previousLastColumnWidth = m_columnWidths.value(record().count()-1);
        m_columnWidths.insert(record().count()-1 , m_tableWidth - (m_sumColumnWidths - previousLastColumnWidth));
        m_sumColumnWidths += m_columnWidths.value(record().count()-1) - previousLastColumnWidth;
        qInfo() << m_sumColumnWidths;
    }
}

int tablemodel::lastColumnWidth()
{
    return m_columnWidths.value(record().count()-1);
}

bool tablemodel::tooSmallTable()
{
    if(m_sumColumnWidths < m_tableWidth)
    {
        return true;
    }
    return false;
}

void tablemodel::print()
{
    qInfo() << "sum width: " << m_sumColumnWidths;
    qInfo() << "table width: " << m_tableWidth;
}
