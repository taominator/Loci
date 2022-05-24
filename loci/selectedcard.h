#ifndef SELECTEDCARD_H
#define SELECTEDCARD_H

#include <QObject>
#include <card.h>

class selectedcard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> data READ getData WRITE setData NOTIFY dataChanged)
public:
    explicit selectedcard(QObject *parent = nullptr);

    //READ functions
    Q_INVOKABLE QList<QString> getData();

    //WRITE functions
    Q_INVOKABLE void setData(QList<QString> data);

    QString getFieldContent(int dataNum);

    void copyData(card* other);

signals:
    void dataChanged();

private:
    QList<QString> m_data;

};

#endif // SELECTEDCARD_H
