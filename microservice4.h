#ifndef MICROSERVICE4_H
#define MICROSERVICE4_H

#include <QMainWindow>
#include <QDebug>

// On inclus la lib nécessaires pour le micro services
#include <QtMqtt/QtMqtt>
#include <QtCore>
#include <QTcpSocket>

// On inclus les classes de gestion
#include "arrosage.h"
#include "brumisation.h"
#include "verrinvelux.h"
#include "chauffage.h"

namespace Ui {
class MicroService4;
}

class MicroService4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MicroService4(QWidget *parent = nullptr);
    ~MicroService4();

private:
    Ui::MicroService4 *ui;
    QMqttClient *m_client;

    // Socket
    QTcpSocket * socket;

    // Class
    arrosage *ar;
    brumisation *br;

    verrinVelux *vr;
    chauffage *ch;

public slots:
    void receiveMessage();
    void brokerDisconnected();
};

#endif // MICROSERVICE4_H
