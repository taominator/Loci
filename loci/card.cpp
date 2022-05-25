#include "card.h"

card::card(QObject *parent, QList<QString> data)
    : QObject{parent}, m_data{data}
{

}

QList<QString> card::getData() {return m_data;}

void card::setData(QList<QString> data)
{
    m_data = data;
    emit dataChanged();
}

QString card::getFieldContent(int dataNum){return m_data[dataNum-1];}
