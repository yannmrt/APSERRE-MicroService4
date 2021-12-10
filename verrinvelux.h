#ifndef VERRINVELUX_H
#define VERRINVELUX_H

#include <QObject>
#include <QDebug>

#include "qmodbustcpclient.h"

class verrinVelux
{
public:
    verrinVelux();
    int status;

public slots:
    void open(QModbusTcpClient * mbus_poseidon);
    void close(QModbusTcpClient * mbus_poseidon);
};

#endif // VERRINVELUX_H
