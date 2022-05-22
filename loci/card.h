#ifndef CARD_H
#define CARD_H

#include <QObject>

class card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> data READ getData WRITE setData)
public:
    explicit card(QObject *parent = nullptr, QList<QString> data = QList<QString>());

    Q_INVOKABLE QList<QString> getData();

    Q_INVOKABLE void setData(QList<QString> data);

    QString getFieldContent(int dataNum);

signals:

private:
    QList<QString> m_data;

};

#endif // CARD_H
