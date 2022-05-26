#ifndef SELECTEDCARD_H
#define SELECTEDCARD_H

#include <QObject>
#include <card.h>
#include <QStringListModel>

class selectedcard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> data READ getData WRITE setData NOTIFY dataChanged)

    //To store pointer to selected card
    Q_PROPERTY (card* selectedCardPointer READ getSelectedCardPointer WRITE setSelectedCardPointer NOTIFY selectedCardPointerChanged)

    //StringListModel for editing user changes (" to "" for csv file)
    Q_PROPERTY(QStringListModel* cardModel READ getCardModel NOTIFY cardModelChanged)

public:
    explicit selectedcard(QObject *parent = nullptr);

    //READ functions
    Q_INVOKABLE QList<QString> getData();
    Q_INVOKABLE card* getSelectedCardPointer();
    Q_INVOKABLE QStringListModel* getCardModel();

    //WRITE functions
    Q_INVOKABLE void setData(QList<QString> data);
    Q_INVOKABLE void setSelectedCardPointer(card* other);

    QString getFieldContent(int dataNum);

    //To save changes to original card class //IMPLEMENT LATER
    void updateSelectedCardData();

    //to edit editing user changes (" to "" for csv file)
    void editData();

signals:
    void dataChanged();
    void selectedCardPointerChanged();
    void cardModelChanged();


private:
    QList<QString> m_data;
    card* m_selectedCardPointer;
    QStringListModel* m_cardModel;

};

#endif // SELECTEDCARD_H
