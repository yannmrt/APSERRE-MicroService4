#include "chauffage.h"

// PORT TCW : RELAI 2

chauffage::chauffage()
{
    this->status = 0;
}

void chauffage::start(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 0) {
        // On lance la débrumisation
        mbus_tcw->forceSingleCoilFC5(101, true);

        qDebug() << "Chauffage start";
    } else {
        qDebug() << "Le chauffage est déjà allumé.";
    }
}

void chauffage::stop(QModbusTcpClient * mbus_tcw)
{
    if(this->status == 1) {
        // On arrête la brumisation
        mbus_tcw->forceSingleCoilFC5(101, false);

        qDebug() << "Chauffage stop";
    } else {
        qDebug() << "Le chauffage est déjà eteind.";
    }
}
