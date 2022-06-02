#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class settings : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int maxWindowWidth Read getMaxWindowWidth WRITE setMaxWindowWidth NOTIFY maxWindowWidthChanged)
public:
    explicit settings(QObject *parent = nullptr);

signals:
    void maxWindowWidthChanged();
private:


};

#endif // SETTINGS_H
