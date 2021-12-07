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
    start();
    stop();
    reset();
};

#endif // CHAUFFAGE_H
