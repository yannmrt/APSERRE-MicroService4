#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include <QObject>
#include <QDebug>

#include "qmodbustcpclient.h"

class chauffage
{
public:
    chauffage();
    int status;

public slots:
    void start(QModbusTcpClient * mbus_tcw);
    void stop(QModbusTcpClient * mbus_tcw);
};

#endif // CHAUFFAGE_H
