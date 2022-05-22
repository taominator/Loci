#include <appfunctions.h>


void readFiles(deck* deck1)
{
    QList<QString> m_fields;
    QList<QString> m_data;

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
        deck1->setFieldNum(m_fields.length());
        deck1->setFields(m_fields);

        while(!file.atEnd())
        {
           m_data.clear();
           QByteArray line = file.readLine();
           byte_data = line.split(',');
           foreach(QByteArray byte, byte_data) //QByteArray undefined in QML
           {
               m_data.append(QString(byte));
           }
           deck1->appendCardList(deck1, m_data);
           deck1->updateCardNum();
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
