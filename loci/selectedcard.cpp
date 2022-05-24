#include "selectedcard.h"

selectedcard::selectedcard(QObject *parent)
    : QObject{parent}
{

}

QList<QString> selectedcard::getData() {return m_data;}

void selectedcard::setData(QList<QString> data) {m_data = data;}

QString selectedcard::getFieldContent(int dataNum){return m_data[dataNum-1];}

void selectedcard::copyData(card* other)
{
    this->m_data = other->getData();
}
