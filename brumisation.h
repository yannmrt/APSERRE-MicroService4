#ifndef BRUMISATION_H
#define BRUMISATION_H

#include <QObject>
#include <qdebug.h>
#include <QTcpSocket>

#include "qmodbustcpclient.h"

class brumisation : public QObject
{
    Q_OBJECT

public:
    explicit brumisation(QObject *parent = nullptr);
    int status;
    QTcpSocket * socket;

public slots:
    void start(QModbusTcpClient * mbus_tcw);
    void stop(QModbusTcpClient * mbus_tcw);
};

#endif // BRUMISATION_H
