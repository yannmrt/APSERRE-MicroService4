#include "verrinvelux.h"

verrinVelux::verrinVelux()
{
    this->status = 0;
}

void verrinVelux::open()
{
    if(this->status == 0) {
        // On lance la débrumisation
    } else {
        qDebug() << "Le velux est déjà ouvert.";
    }
}

void verrinVelux::close()
{
    if(this->status == 1) {
        // On arrête la brumisation
    } else {
        qDebug() << "Le velux est déjà fermé.";
    }
}

void verrinVelux::reset()
{

}
