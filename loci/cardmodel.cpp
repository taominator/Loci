#include "cardmodel.h"

cardmodel::cardmodel(QObject *parent)
    : QAbstractListModel{parent}
{
    QObject::connect(this, &cardmodel::dataChanged, this, &cardmodel::updateSelectedCard);

}


void cardmodel::setSelectedCard(deck *selectedDeckPointer, card *selectedCardPointer)
{
    m_selectedDeckPointer = selectedDeckPointer;
    m_selectedCardPointer = selectedCardPointer;

    m_Data.clear();

    for(int i = 0; i < selectedDeckPointer->getFields().length(); i++)
    {
        m_Data.append(Data(selectedDeckPointer->getFields().at(i), selectedCardPointer->getData().at(i)));
    }
}

void cardmodel::updateSelectedCard() //NOT COMPLETE. Later implement changing data to something appropriate for csv file
{
    QList<QString> data;
    for(int i = 0; i < m_Data.length(); i++)
    {
        data.append(m_Data.at(i).data);
    }

    m_selectedCardPointer->setData(data);
}



int cardmodel::rowCount( const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return m_Data.length();
}


QVariant cardmodel::data(const QModelIndex &index, int role) const
{
    if ( !index.isValid() )
        return QVariant();

    const Data &data = m_Data.at(index.row());

    if ( role == FieldRole ){
        return data.field;
    }
    else if ( role == DataRole )
        return data.data;
    else
        return QVariant();
}


//--> slide
QHash<int, QByteArray> cardmodel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {FieldRole, "field"},
        {DataRole, "data"}
    };
    return mapping;
}
//<-- slide
