#include "verrinvelux.h"

// PORT TCW : RELAI 3

verrinVelux::verrinVelux()
{
    this->status = 0;
}

void verrinVelux::open(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(102, true);
    qDebug() << "Velux ouvert";
}

void verrinVelux::close(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(102, false);
    qDebug() << "Velux fermer";
}
