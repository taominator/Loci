#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <card.h>

class deck : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fieldNum READ getFieldNum WRITE setFieldNum NOTIFY fieldNumChanged);
    Q_PROPERTY(QList<QString> fields READ getFields WRITE setFields NOTIFY fieldsChanged)
    Q_PROPERTY(QList<card*> cardList READ getCardList WRITE setCardList NOTIFY cardListChanged)

public:
    explicit deck(QObject *parent = nullptr, int fieldNum = 0, QList<QString> fields = QList<QString>(), QList<card*> cardList = QList<card*>(), int cardNum = 0);

    //READ functions
    Q_INVOKABLE int getFieldNum();
    Q_INVOKABLE QList<QString> getFields();
    Q_INVOKABLE QList<card*> getCardList();

    //WRITE functions
    Q_INVOKABLE void setFieldNum(int num);
    Q_INVOKABLE void setFields(QList<QString> fields);
    Q_INVOKABLE void setCardList(QList<card*> fields);

    int getCardNum();
    void updateCardNum();

    void appendCardList(QObject *parent = nullptr, QList<QString> data = QList<QString>());

signals:
    void fieldNumChanged();
    void fieldsChanged();
    void cardListChanged();

private:
    int m_fieldNum;
    QList<QString> m_fields;
    QList<card*> m_cardList;

    int m_cardNum;
};

#endif // DECK_H
