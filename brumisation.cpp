#include "brumisation.h"

brumisation::brumisation(QObject *parent) : QObject(parent)
{
    this->status = 0;
}

void brumisation::start()
{
    if(this->status == 0) {
        // On lance la débrumisation
    } else {
        qDebug() << "La brumisation est déjà en cours.";
    }
}

void brumisation::stop()
{
    if(this->status == 1) {
        // On arrête la brumisation
    } else {
        qDebug() << "La brumiastion est déjà en état arrêtée.";
    }
}

void brumisation::reset()
{

}
