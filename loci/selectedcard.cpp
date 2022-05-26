#include "selectedcard.h"

selectedcard::selectedcard(QObject *parent)
    : QObject{parent}
{
    m_cardModel->setParent(this);

}

QList<QString> selectedcard::getData() {return m_data;}
card* selectedcard::getSelectedCardPointer() {return m_selectedCardPointer;}
QStringListModel* selectedcard::getCardModel() {return m_cardModel;}



void selectedcard::setData(QList<QString> data)
{
    m_data = data;
    emit dataChanged();
}
void selectedcard::setSelectedCardPointer(card *other)
{
    m_selectedCardPointer = other;
    m_data = other->getData();
    m_cardModel->setStringList(m_data);
    emit selectedCardPointerChanged();
}



QString selectedcard::getFieldContent(int dataNum){return m_data[dataNum-1];}
void selectedcard::updateSelectedCardData(){m_selectedCardPointer->setData(m_data);}


/*void selectedcard::cardModelChanged()
{
    editData();
    updateSelectedCardData();
}*/
