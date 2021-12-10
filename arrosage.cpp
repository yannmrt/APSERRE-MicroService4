#include "arrosage.h"

arrosage::arrosage()
{
    this->status = 0;
}

void arrosage::start(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 0) {
        // On lance l'arrosage
        //mbus_tcw->forceSingleCoilFC5("", "value");
    } else {
        qDebug() << "L'arrosage est déjà en cours.";
    }
}

void arrosage::stop(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 1) {
        // On arrête l'arrosage
    } else {
        qDebug() << "L'arrosage est déjà en état arrêtée.";
    }
}

