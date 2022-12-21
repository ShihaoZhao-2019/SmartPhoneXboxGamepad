#include "TaskControl.h"

TaskControl::TaskControl()
{
    //init xbox information
    xbox_device = QSharedPointer<Xbox>(Xbox::getInstance());
    //init tcp and udp
    tcp_client = QSharedPointer<TransTCP>(new TransTCP());
    udp_client = QSharedPointer<TransUDP>(new TransUDP());
    udp_client.get()->SetTCPPort(LOCAL_TCP_PORT);
    //set cycle taskend T is 1ms
    connect(&timer,&QTimer::timeout,this,&TaskControl::ScheduledTrans);
    timer.setInterval(SEND_CYCLE);

    //set cycle UDP T is 1s
    connect(&timer_udp,&QTimer::timeout,this,&TaskControl::ScheduledUDP);
    timer_udp.setInterval(UDP_SEND_CYCLE);
    timer_udp.start();

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
    timer_udp.stop();
}

void TaskControl::SendEnd()
{
    timer.stop();
}

void TaskControl::ScheduledTrans()
{
    tcp_client.get()->UpdateSendData(xbox_device.get()->GetPXboxState(),sizeof(XINPUT_STATE));
    tcp_client.get()->Send();
    MyPrint(&xbox_device.get()->GetPXboxState()->Gamepad);
}

void TaskControl::TaskBegin()
{
    SendStart();
}

void TaskControl::ScheduledUDP()
{
    qDebug() << "my address have send by udp,send len is" << udp_client.get()->Send()
             <<"ip:" << udp_client.get()->GetLocalHostInt()\
             << "port" << udp_client.get()->GetTCPPort() << Qt::endl;
}
