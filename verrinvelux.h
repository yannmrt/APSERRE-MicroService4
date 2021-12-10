#ifndef VERRINVELUX_H
#define VERRINVELUX_H

#include <QObject>
#include <QDebug>

class verrinVelux
{
public:
    verrinVelux();
    int status;

public slots:
    void open();
    void close();
    void reset();
};

#endif // VERRINVELUX_H
