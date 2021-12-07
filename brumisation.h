#ifndef BRUMISATION_H
#define BRUMISATION_H

#include <QObject>
#include <qdebug.h>

class brumisation : public QObject
{
    Q_OBJECT

public:
    explicit brumisation(QObject *parent = nullptr);
    int status;

public slots:
    void start();
    void stop();
    void reset();
    void getStatus();
};

#endif // BRUMISATION_H
