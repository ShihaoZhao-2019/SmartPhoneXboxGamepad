#pragma once
#include "TransCOM.h"
#include <QUdpSocket>
#include <QtNetwork>

#define UDP_PORT		1998

#define _IP_MARK        "."
class TransUDP :
    public TransCOM
{
public:
    TransUDP();
    int Send() ;
    ~TransUDP() override;
    QString &GetLocalHost();
    unsigned int &GetLocalHostInt();
    void SetTCPPort(unsigned short port);
    unsigned short &GetTCPPort();

private:
    void UpdateSendBuff() ;
    QString GetLocalIpAddress();
    unsigned int IPtoINT(const std::string & strIP);
private:
    QSharedPointer<QUdpSocket> my_udp_socket;
    QString local_ip_address;
    unsigned int local_ip_address_int;
    unsigned short tcp_port;



};

