#include "microservice4.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MicroService4 w;
    w.show();

    return a.exec();
}
