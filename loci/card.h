#ifndef CARD_H
#define CARD_H

#include <QObject>

class card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> data READ getData WRITE setData NOTIFY dataChanged)
public:
    explicit card(QObject *parent = nullptr, QList<QString> data = QList<QString>());

    //READ functions
    Q_INVOKABLE QList<QString> getData();

    //WRITE functions
    Q_INVOKABLE void setData(QList<QString> data);

    QString getFieldContent(int dataNum);


signals:
    void dataChanged();

private:
    QList<QString> m_data;

};

#endif // CARD_H
