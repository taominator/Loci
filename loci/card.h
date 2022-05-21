#ifndef CARD_H
#define CARD_H

#include <QObject>

class card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> data READ getData WRITE setData)
public:
    explicit card(QObject *parent = nullptr, QList<QString> data = QList<QString>());

    QList<QString> getData();
    QString getFieldContent(int dataNum);

    void setData(QList<QString> data);

signals:

private:
    QList<QString> m_data;

};

#endif // CARD_H
