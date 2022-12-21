#ifndef TASKCONTROL_H
#define TASKCONTROL_H

#include <QObject>
#include <Communication/TransTCP.h>
#include <Communication/TransUDP.h>
#include <Xbox/Xbox.h>
#include <QTime>
#define SEND_CYCLE                   2
#define UDP_SEND_CYCLE               1000


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
    void ScheduledUDP();
private:
    QSharedPointer<TransTCP> tcp_client;
    QSharedPointer<TransUDP> udp_client;
    QSharedPointer<Xbox> xbox_device;
    QTimer timer;
    QTimer timer_udp;

};

#endif // TASKCONTROL_H
