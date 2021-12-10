#include "microservice4.h"
#include "ui_microservice4.h"

// Configuration du serveur MQTT
#define HOSTNAME "192.168.65.104"
#define PORT 1883

MicroService4::MicroService4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MicroService4)
{
    ui->setupUi(this);

    // On définie la mémoire pour nos classes arrosage et brumisation
    ar = new arrosage();
    br = new brumisation();

    // Connexion au serveur MQTT
    m_client = new QMqttClient(this);
    m_client->setHostname(HOSTNAME);
    m_client->setPort(PORT);

    QObject::connect(m_client, SIGNAL(connect()), this, SLOT(onMqttConnected()));

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
    if(topic.name() == "misting") {
        if(message == "start_misting") {
            br->start();
        } else if(message == "stop_misting") {
            br->stop();
        }
    }

    if(topic.name() == "watering") {
        if(message == "start_watering") {
            ar->start();
        } else if(message == "stop_watering") {
            ar->stop();
        }
    }

    if(topic.name() == "heating") {
        if(message == "start_heating") {

        } else if(message == "stop_heating") {

        }
    }

    if(topic.name() == "vasistas") {
        if(message == "start_vasistas") {

        } else if(message == "stop_vasistas") {

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
