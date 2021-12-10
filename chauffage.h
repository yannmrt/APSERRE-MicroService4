#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include <QObject>
#include <QDebug>

class chauffage
{
public:
    chauffage();
    int status;

public slots:
    void start();
    void stop();
    void reset();
};

#endif // CHAUFFAGE_H
