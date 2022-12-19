#include "TaskControl.h"

TaskControl::TaskControl()
{
    //init xbox information
    xbox_device = QSharedPointer<Xbox>(Xbox::getInstance());
    //init tcp and udp
    tcp_client = QSharedPointer<TransTCP>(new TransTCP());
    udp_client = QSharedPointer<TransUDP>(new TransUDP());
    udp_client.get()->SetTCPPort(LOCAL_TCP_PORT);
    qDebug() << "my address have send by udp,send len is" << udp_client.get()->Send()
             <<"ip:" << udp_client.get()->GetLocalHostInt()\
             << "port" << udp_client.get()->GetTCPPort() << Qt::endl;
    //set cycle taskend T is 1ms
    connect(&timer,&QTimer::timeout,this,&TaskControl::ScheduledTrans);
    timer.setInterval(SEND_CYCLE);
    // when tcp connect, cycle send will start
    connect(tcp_client.get(),&TransTCP::tcp_connect,this,&TaskControl::TaskBegin);

}

QSharedPointer<Xbox> TaskControl::GetTcpXboxDevice()
{
    return xbox_device;
}

void TaskControl::SendStart()
{
    timer.start();
}

void TaskControl::SendEnd()
{
    timer.stop();
}

void TaskControl::ScheduledTrans()
{
    tcp_client.get()->UpdateSendData(xbox_device.get()->GetPXboxState(),sizeof(XINPUT_STATE));
    tcp_client.get()->Send();
}

void TaskControl::TaskBegin()
{
    SendStart();
}
