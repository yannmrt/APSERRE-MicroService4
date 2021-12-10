#include "microservice4.h"
#include "ui_microservice4.h"

MicroService4::MicroService4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MicroService4)
{
    ui->setupUi(this);

    // On définie la mémoire pour nos classes arrosage et brumisation
    ar = new arrosage();
    br = new brumisation();
    ch = new chauffage();
    vr = new verrinVelux();

    // Connexion au serveur MQTT
    m_client = new QMqttClient(this);
    m_client->setHostname("192.168.65.104");
    m_client->setPort(1883);

    QObject::connect(m_client, SIGNAL(connected()), this, SLOT(onMqttConnected()));

    m_client->connectToHost();
}

void MicroService4::onMqttConnected()
{
    qDebug() << "Connexion au broker MQTT réussie.";

    // On subscribe le topic arrosage
    m_client->subscribe(QMqttTopicFilter("watering"));

    // On subscribe le topic brumisation
    m_client->subscribe(QMqttTopicFilter("misting"));

    // On subscribe le topic chauffage
    m_client->subscribe(QMqttTopicFilter("heating"));

    // On subscribe le topic velux
    m_client->subscribe(QMqttTopicFilter("vasistas"));

    // Si on reçois un message sur l'un des topic alors on envoi vers la fonctio onMqttreceiveMessage
    QObject::connect(m_client, &QMqttClient::messageReceived, this, &MicroService4::onMqttReceiveMessage);
}

void MicroService4::onMqttReceiveMessage(const QByteArray &message, const QMqttTopicName &topic)
{
    // On instancie les classe modbus
    mbus_tcw = new QModbusTcpClient("192.168.65.8", 502, this); // Carte TCW
    mbus_poseidon = new QModbusTcpClient("192.168.64.58", 502, this); // Carte Poseidon


    if(topic.name() == "misting") {
        if(message == "start_misting") {
            br->start(mbus_tcw);
        } else if(message == "stop_misting") {
            br->stop(mbus_tcw);
        }
    }

    if(topic.name() == "watering") {
        if(message == "start_watering") {
            ar->start(mbus_tcw);
        } else if(message == "stop_watering") {
            ar->stop(mbus_tcw);
        }
    }

    if(topic.name() == "heating") {
        if(message == "start_heating") {
            ch->start(mbus_poseidon);
        } else if(message == "stop_heating") {
            ch->stop(mbus_poseidon);
        }
    }

    if(topic.name() == "vasistas") {
        if(message == "start_vasistas") {
            vr->open(mbus_poseidon);
        } else if(message == "stop_vasistas") {
            vr->close(mbus_poseidon);
        }
    }
}

void MicroService4::onBrokerDisconnected()
{
    qDebug() << "Broker MQTT perdu.";
}

MicroService4::~MicroService4()
{
    delete ui;
}
