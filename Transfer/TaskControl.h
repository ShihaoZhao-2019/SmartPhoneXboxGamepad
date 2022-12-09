#ifndef TASKCONTROL_H
#define TASKCONTROL_H

#include <QObject>
#include <Communication/TransTCP.h>
#include <Communication/TransUDP.h>
#include <Xbox/Xbox.h>

class TaskControl
{
public:
    TaskControl();
private:
    QSharedPointer<TransTCP> tcp_client;
    QSharedPointer<TransUDP> udp_client;
    QSharedPointer<Xbox> xbox_device;
};

#endif // TASKCONTROL_H
