#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QDir>



class fileReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> m_fields READ fields CONSTANT)
    Q_PROPERTY(QList<QString> m_data READ data CONSTANT)
public:
    fileReader(QObject *parent = nullptr);

    Q_INVOKABLE QList<QString> fields();
    Q_INVOKABLE QList<QString> data();

    void readFile();
private:
    QList<QString> m_fields;
    QList<QString> m_data;
};

#endif // FILEREADER_H
