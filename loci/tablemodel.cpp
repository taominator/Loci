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
    int j = 0;
    while(j < 10)
    {
        m_columnWidths[j] = 0;
        j++;
    }
    for(int i = j; i < record().count(); i ++){
        m_columnWidths[i] = m_defaultColumnWidth;
    }
    m_sumColumnWidths = (record().count() - 10) * m_defaultColumnWidth;
    rectifyLastColumnWidth();
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

void tablemodel::updateSumColumnWidths()
{
    m_sumColumnWidths = 0;
    for(int i = 0; i < record().count(); i ++){
        m_sumColumnWidths += m_columnWidths.value(i);
    }

}

void tablemodel::rectifyLastColumnWidth()
{
    if(m_tableWidth > m_sumColumnWidths){
        int previousLastColumnWidth = m_columnWidths.value(record().count()-1);
        m_columnWidths.insert(record().count()-1 , m_tableWidth - (m_sumColumnWidths - previousLastColumnWidth));
        m_sumColumnWidths += m_columnWidths.value(record().count()-1) - previousLastColumnWidth;
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

bool tablemodel::containsRow(int index)
{
    return m_selectedRows.contains(index);
}

QString tablemodel::colorProvider(int index)
{
    if(m_selectedRows.contains(index))
    {
        return "blue";
    }
    return "cyan";
}

void tablemodel::leftClick(int index)
{
    m_selectedRows.clear();
    m_selectedRows.append(index);
    qInfo() << m_selectedRows;
}

void tablemodel::ctrlClick(int index)
{
    if(m_selectedRows.contains(index)){
        m_selectedRows.removeOne(index);
    }
    else{
        m_selectedRows.append(index);
    }
}

void tablemodel::shiftClick(int index)
{
    if(m_selectedRows.isEmpty())
    {
        return;
    }
    int lastIndex = m_selectedRows.last();

    if (index > lastIndex){
        for (int i = lastIndex + 1; i <= index; i++)
        {
            m_selectedRows.append(i);
        }
    }

    if (index < lastIndex){
        for (int i = index; i < lastIndex; i++)
        {
            m_selectedRows.append(i);
        }
    }
}

void tablemodel::ctrlAll(int num_rows)
{
    m_selectedRows.clear();
    for (int i = 0; i < num_rows; i++)
    {
        m_selectedRows.append(i);
    }
}

