#include "arrosage.h"

// PORT TCW : RELAI 4

arrosage::arrosage()
{
    this->status = 0;
}

void arrosage::start(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 0) {
        // On lance l'arrosage
        mbus_tcw->forceSingleCoilFC5(103, true);

        qDebug() << "Arrosage start";
    } else {
        qDebug() << "L'arrosage est déjà en cours.";
    }
}

void arrosage::stop(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 1) {
        // On arrête l'arrosage
        mbus_tcw->forceSingleCoilFC5(103, false);

        qDebug() << "Arrosage stop";
    } else {
        qDebug() << "L'arrosage est déjà en état arrêtée.";
    }
}

