#include "microservice4.h"
#include "ui_microservice4.h"

// Configuration du serveur MQTT
#define HOSTNAME "192.168.0.0"
#define PORT 1178

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

    // On définie les signaux et on les rediriges vers les slots
    QObject::connect(m_client, SIGNAL(messageReceived()), this, SLOT(receiveMessage()));
    QObject::connect(m_client, SIGNAL(disconnected()), this, SLOT(brokerDisconnected()));

}

void MicroService4::receiveMessage()
{
    // Initialisation du socket
    socket = new QTcpSocket(this);
        QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
        QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisonnected()));
        QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(messagerecu()));
        socket->connectToHost( "192.168.64.148", 178);

    // On alloue la mémoire pour les fonctions
    br = new brumisation();
    ar = new arrosage();
}

void MicroService4::brokerDisconnected()
{
    qDebug() << "Broker MQTT perdu.";
}

MicroService4::~MicroService4()
{
    delete ui;
}
