#include "filereader.h"
deck deck1;

fileReader::fileReader(QObject *parent): QObject(parent) {}

QList<QString> fileReader::getFields()
{
    return m_fields;
}

QList<QString> fileReader::getData()
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
        foreach(QByteArray byte, byte_fields) //QByteArray undefined in QML
        {
            m_fields.append(QString(byte));
        }
        deck1.setFieldNum(m_fields.length());
        deck1.setFields(m_fields);

        while(!file.atEnd())
        {
           m_data.clear();
           QByteArray line = file.readLine();
           byte_data = line.split(',');
           foreach(QByteArray byte, byte_data) //QByteArray undefined in QML
           {
               m_data.append(QString(byte));
           }
           deck1.appendCardList(nullptr, m_data);
        }
        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    qInfo() << byte_fields;
    qInfo() << byte_data;

}
