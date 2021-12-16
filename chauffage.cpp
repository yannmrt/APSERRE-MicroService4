#include "chauffage.h"

// PORT TCW : RELAI 2

chauffage::chauffage()
{
    this->status = 0;
}

void chauffage::start(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(101, true);
    qDebug() << "Chauffage demarer";
}

void chauffage::stop(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(101, false);
    qDebug() << "Chauffage arreter";
}
