#include "filereader.h"

fileReader::fileReader(QObject *parent): QObject(parent) {}

QList<QString> fileReader::fields()
{
    return m_fields;
}

QList<QString> fileReader::data()
{
    return m_data;
}

void fileReader::readFile()
{
    m_fields.clear();
    m_data.clear();

    QList<QByteArray> byte_fields;
    QList<QByteArray> byte_data;

    QString fileName = "C:/Git Repository/Loci/loci/test.txt";
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray line = file.readLine();

        byte_fields = line.split(',');

        while(!file.atEnd())
        {
           QByteArray line = file.readLine();

           byte_data += line.split(',');
        }

        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    foreach(QByteArray byte, byte_fields) //QByteArray undefined in QML
    {
        m_fields.append(QString(byte));
    }

    foreach(QByteArray byte, byte_data) //QByteArray undefined in QML
    {
        m_data.append(QString(byte));
    }

    qInfo() << byte_fields;
    qInfo() << byte_data;
}
