#include "arrosage.h"

arrosage::arrosage()
{
    this->status = 0;
}

void arrosage::start()
{
    if(this->status == 0) {
        // On lance l'arrosage
    } else {
        qDebug() << "L'arrosage est déjà en cours.";
    }
}

void arrosage::stop()
{
    if(this->status == 1) {
        // On arrête l'arrosage
    } else {
        qDebug() << "L'arrosage est déjà en état arrêtée.";
    }
}

void arrosage::reset()
{

}

}
