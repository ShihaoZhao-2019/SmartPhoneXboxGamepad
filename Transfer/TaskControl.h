#ifndef TASKCONTROL_H
#define TASKCONTROL_H

#include <QObject>
#include <Communication/TransTCP.h>
#include <Communication/TransUDP.h>
#include <Xbox/Xbox.h>
#include <QTime>
#define SEND_CYCLE                   1


class TaskControl:
        public QObject
{
public:
    TaskControl();
    QSharedPointer<Xbox> GetTcpXboxDevice();
private:
    void SendStart();
    void SendEnd();
    void ScheduledTrans();
    void TaskBegin();
private:
    QSharedPointer<TransTCP> tcp_client;
    QSharedPointer<TransUDP> udp_client;
    QSharedPointer<Xbox> xbox_device;
    QTimer timer;

};

#endif // TASKCONTROL_H
