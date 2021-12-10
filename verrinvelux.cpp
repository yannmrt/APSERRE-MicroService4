#include "verrinvelux.h"

verrinVelux::verrinVelux()
{
    this->status = 0;
}

void verrinVelux::open(QModbusTcpClient * mbus_poseidon)
{
    if(this->status == 0) {
        // On lance la débrumisation
    } else {
        qDebug() << "Le velux est déjà ouvert.";
    }
}

void verrinVelux::close(QModbusTcpClient * mbus_poseidon)
{
    if(this->status == 1) {
        // On arrête la brumisation
    } else {
        qDebug() << "Le velux est déjà fermé.";
    }
}
