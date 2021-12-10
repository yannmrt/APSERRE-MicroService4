#include "verrinvelux.h"

// PORT TCW : RELAI 3

verrinVelux::verrinVelux()
{
    this->status = 0;
}

void verrinVelux::open(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 0) {
        // On lance la débrumisation
        mbus_tcw->forceSingleCoilFC5(102, true);

        qDebug() << "Velux open";
    } else {
        qDebug() << "Le velux est déjà ouvert.";
    }
}

void verrinVelux::close(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 1) {
        // On arrête la brumisation
        mbus_tcw->forceSingleCoilFC5(102, false);

        qDebug() << "Velux close";
    } else {
        qDebug() << "Le velux est déjà fermé.";
    }
}
