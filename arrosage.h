#ifndef ARROSAGE_H
#define ARROSAGE_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

#include "qmodbustcpclient.h"

class arrosage
{
private:
    int status;
public:
    arrosage();

public slots:
    void start(QModbusTcpClient * mbus_tcw);
    void stop(QModbusTcpClient * mbus_tcw);
};

#endif // ARROSAGE_H
