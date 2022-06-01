#include "tablemodel.h"

tablemodel::tablemodel(QObject *parent)
    : QSqlQueryModel{parent}
{

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
        m_columnWidths[i] = 100;
    }
}

int tablemodel::getColumnWidth(int n){
    return m_columnWidths.value(n);
}
