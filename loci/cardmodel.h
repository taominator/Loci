#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <QAbstractListModel>
#include <deck.h>
#include <card.h>

struct Data {
    Data() {}
    Data( QString field, QString data)
        : field(field), data(data) {}
    QString field;
    QString data;
};

class cardmodel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit cardmodel(QObject *parent = nullptr);

    void setSelectedCard(deck* selectedDeckPointer = nullptr, card* selectedCardPointer = nullptr);


    enum Roles {
        FieldRole = Qt::UserRole,
        DataRole
    };

    int rowCount(const QModelIndex& parent) const override;
    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;
    QHash<int, QByteArray> roleNames() const override;


signals:

public slots:
    void updateSelectedCard();

private:
    QList<Data> m_Data;

    deck* m_selectedDeckPointer;
    card* m_selectedCardPointer;

};

#endif // CARDMODEL_H
