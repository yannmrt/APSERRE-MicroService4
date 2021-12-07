#ifndef ARROSAGE_H
#define ARROSAGE_H

#include <QObject>
#include <QDebug>

class arrosage
{
private:
    int status;
public:
    arrosage();
public slots:
    void start();
    void stop();
    void reset();
};

#endif // ARROSAGE_H
