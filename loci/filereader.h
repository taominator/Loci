#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <deck.h>
#include <card.h>


class fileReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> m_fields READ getFields CONSTANT)
    Q_PROPERTY(QList<QString> m_data READ getData CONSTANT)
public:
    explicit fileReader(QObject *parent = nullptr);

    Q_INVOKABLE QList<QString> getFields(); //Either Q_INVOKABLE or no ()paranthesis for function call in QML
    Q_INVOKABLE QList<QString> getData();

    void readFile();
private:
    QList<QString> m_fields;
    QList<QString> m_data;
};

#endif // FILEREADER_H
