#include "arrosage.h"

// PORT TCW : RELAI 4

arrosage::arrosage()
{
    this->status = 0;
}

void arrosage::start(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(103, true);
    qDebug() << "Arrosage demarrer";
}

void arrosage::stop(QModbusTcpClient * mbus_tcw)
{
   mbus_tcw->forceSingleCoilFC5(103, false);
   qDebug() << "Arrosage arreter";
}

