#include "deck.h"

deck::deck(QObject *parent, int fieldNum, QList<QString> fields, QList<card*> cardList, int cardNum)
    : QObject{parent}, m_fieldNum(fieldNum), m_fields(fields), m_cardList(cardList), m_cardNum(cardNum)
{

}

int deck::getFieldNum() {return m_fieldNum;}
QList<QString> deck::getFields() {return m_fields;}
QList<card*> deck::getCardList() {return m_cardList;} // QList<QObject> not possible! Must be QList<*QObject>
int deck::getCardNum() {return m_cardNum;}



void deck::setFieldNum(int num)
{
    m_fieldNum = num;
    emit fieldNumChanged();
}
void deck::setFields(QList<QString> fields)
{
    m_fields = fields;
    emit fieldsChanged();
}
void deck::setCardList(QList<card*> cardList)
{
    m_cardList = cardList;
    emit cardListChanged();
} // QList<QObject> not possible! Must be QList<*QObject>



void deck::updateCardNum()
{
    m_cardNum = m_cardList.length();
}

void deck::appendCardList(QObject *parent, QList<QString> data)
{
    card* card1 = new card(parent, data);
    m_cardList.append(card1);
}
