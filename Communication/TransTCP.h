#ifndef TRANSTCP_H
#define TRANSTCP_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QSharedPointer>
#include <QNetworkInterface>
#include "TransCOM.h"

#define LOCAL_TCP_PORT   1111

class TransTCP:
        public TransCOM
{
public:
    TransTCP();
    int Send();
    void UpdateSendData(const void* packet,int len);

private:
    QSharedPointer<QTcpServer> tcp_server;
    QSharedPointer<QTcpSocket> tcp_client;
    unsigned int client_address;
    unsigned int client_port;
    std::mutex send_buffer_mutuex;


};

#endif // TRANSTCP_H
