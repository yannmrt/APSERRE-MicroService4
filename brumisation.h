#ifndef BRUMISATION_H
#define BRUMISATION_H

#include <QObject>
#include <qdebug.h>
#include <QTcpSocket>

class brumisation : public QObject
{
    Q_OBJECT

public:
    explicit brumisation(QObject *parent = nullptr);
    int status;
    QTcpSocket * socket;

public slots:
    void start();
    void stop();
    void reset();
};

#endif // BRUMISATION_H
