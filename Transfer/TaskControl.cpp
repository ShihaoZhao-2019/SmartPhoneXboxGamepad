#include "TaskControl.h"

TaskControl::TaskControl()
{
    tcp_client = QSharedPointer<TransTCP>(new TransTCP());
    udp_client = QSharedPointer<TransUDP>(new TransUDP());
    udp_client.get()->SetTCPPort(LOCAL_TCP_PORT);
//    qDebug() << udp_client.get()->GetLocalHostInt() << Qt::endl;
//    qDebug() << udp_client.get()->GetTCPPort()<< Qt::endl ;
    qDebug() << "my address have send by udp,send len is" << udp_client.get()->Send()
             <<"ip:" << udp_client.get()->GetLocalHostInt()\
             << "port" << udp_client.get()->GetTCPPort() << Qt::endl;
}
