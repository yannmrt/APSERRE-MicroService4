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

void MicroService4::onModbusConnected(void * userObj)
{
    MessageData * data = (MessageData*)userObj;

    QModbusTcpClient * mbus_tcw = (QModbusTcpClient*)sender();

    if(data->topic == "misting") {
        if(data->message == "start_misting") {
            br->start(mbus_tcw);
        } else if(data->message == "stop_misting") {
            br->stop(mbus_tcw);
        }
    }

    if(data->topic == "watering") {
        if(data->message == "start_watering") {
            ar->start(mbus_tcw);
        } else if(data->message == "stop_watering") {
            ar->stop(mbus_tcw);
        }
    }

    if(data->topic == "heating") {
        if(data->message == "start_heating") {
            ch->start(mbus_tcw);
        } else if(data->message == "stop_heating") {
            ch->stop(mbus_tcw);
        }
    }

    if(data->topic == "vasistas") {
        if(data->message == "start_vasistas") {
            vr->open(mbus_tcw);
        } else if(data->message == "stop_vasistas") {
            vr->close(mbus_tcw);
        }
    }


}

void MicroService4::onMqttReceiveMessage(const QByteArray &message, const QMqttTopicName &topic)
{
    MessageData * data = new MessageData();
    data->topic = topic.name();
    data->message = QString(message);

    // On instancie les classe modbus
    mbus_tcw = new QModbusTcpClient("192.168.65.19", 502, this, data); // Carte TCW
    // mbus_poseidon = new QModbusTcpClient("192.168.64.58", 502, this); // Carte Poseidon
    QObject::connect(mbus_tcw, &QModbusTcpClient::onConnected, this, &MicroService4::onModbusConnected);
    QObject::connect(mbus_tcw, &QModbusTcpClient::onForceSingleCoilSentence, this, &MicroService4::onForceSingleCoilSentence);

    mbus_tcw->connectToHost();


}

void MicroService4::onForceSingleCoilSentence(bool writeSuccess, quint16 coilAddress, bool value)
{
    QModbusTcpClient * client = (QModbusTcpClient*)sender();
    client->disconnectFromHost();
    sender()->deleteLater();
}

void MicroService4::onBrokerDisconnected()
{
    qDebug() << "Broker MQTT perdu.";
}

MicroService4::~MicroService4()
{
    delete ui;
}
