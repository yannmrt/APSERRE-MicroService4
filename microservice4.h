#ifndef MICROSERVICE4_H
#define MICROSERVICE4_H

#include <QMainWindow>
#include <QDebug>

// On inclus la lib nécessaires pour le micro services
#include <QtMqtt/QtMqtt>
#include <QtCore>

// On inclus les classes de gestion
#include "arrosage.h"
#include "brumisation.h"
#include "verrinvelux.h"
#include "chauffage.h"

// On inclus la classe nécessaire pour communiquer avec les cartes
#include "qmodbustcpclient.h"

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

    // Class
    arrosage *ar;
    brumisation *br;
    verrinVelux *vr;
    chauffage *ch;

    // Com modbus
    QModbusTcpClient *mbus_tcw;
    QModbusTcpClient *mbus_poseidon;

public slots:
    void onMqttConnected();
    void onMqttReceiveMessage(const QByteArray &message, const QMqttTopicName &topic);
    void onBrokerDisconnected();
};

#endif // MICROSERVICE4_H
