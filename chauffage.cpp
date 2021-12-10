#include "chauffage.h"

chauffage::chauffage()
{
    this->status = 0;
}

void chauffage::start(QModbusTcpClient * mbus_poseidon)
{
    if(this->status == 0) {
        // On lance la débrumisation
    } else {
        qDebug() << "Le chauffage est déjà allumé.";
    }
}

void chauffage::stop(QModbusTcpClient * mbus_poseidon)
{
    if(this->status == 1) {
        // On arrête la brumisation
    } else {
        qDebug() << "Le chauffage est déjà eteind.";
    }
}
