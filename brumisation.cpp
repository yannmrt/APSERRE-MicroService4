#include "brumisation.h"

// PORT TCW: RELAI 1

brumisation::brumisation(QObject *parent) : QObject(parent)
{
    this->status = 0;
}

void brumisation::start(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 0) {
        // On lance la débrumisation
        mbus_tcw->forceSingleCoilFC5(100, true);

        qDebug() << "Brumisation start";
    } else {
        qDebug() << "La brumisation est déjà en cours.";
    }
}

void brumisation::stop(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 1) {
        // On arrête la brumisation
        mbus_tcw->forceSingleCoilFC5(100, false);

        qDebug() << "Brumisation stop";
    } else {
        qDebug() << "La brumiastion est déjà en état arrêtée.";
    }
}
