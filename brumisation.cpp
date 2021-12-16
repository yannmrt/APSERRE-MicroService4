#include "brumisation.h"

// PORT TCW: RELAI 1

brumisation::brumisation(QObject *parent) : QObject(parent)
{
    this->status = 0;
}

void brumisation::start(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(100, true);
    qDebug() << "Brumisation demarer";
}

void brumisation::stop(QModbusTcpClient * mbus_tcw)
{
    mbus_tcw->forceSingleCoilFC5(100, false);
    qDebug() << "Brumisation arreter";
}
