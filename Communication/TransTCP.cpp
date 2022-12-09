#include "TransTCP.h"

TransTCP::TransTCP()
{
    tcp_server = QSharedPointer<QTcpServer>(new QTcpServer());
    if(tcp_server.get()->listen(QHostAddress::AnyIPv4,LOCAL_TCP_PORT) == false)
    {
        printf("tcp listen failed\n");
    }
//    tcp_server.get()->waitForNewConnection();
//    tcp_client = QSharedPointer<QTcpSocket>(tcp_server.get()->nextPendingConnection());
//    client_address = tcp_client.get()->peerAddress().toIPv4Address();
//    client_port = tcp_client.get()->peerPort();
//    printf("client connect success\n");
//    printf("client ip:%d\n",client_address);
//    printf("client port:%d\n",client_port);
    connect(tcp_server.get(),&QTcpServer::newConnection,this,[&](){
        tcp_client = QSharedPointer<QTcpSocket>(tcp_server.get()->nextPendingConnection());
        client_address = tcp_client.get()->peerAddress().toIPv4Address();
        client_port = tcp_client.get()->peerPort();
        qDebug() << "client connect success" << Qt::endl;
        qDebug() << "client ip:"<< client_address << Qt::endl;
        qDebug() << "client port"<< client_port;
    });
}

int TransTCP::Send()
{
    std::lock_guard<std::mutex> lock(send_buffer_mutuex);
    int send_len = tcp_client.get()->write((char*)SendBuff,MAX_SEND_BUF_LEN);
    return send_len;
}

void TransTCP::UpdateSendData(const void *packet, int len)
{
    std::lock_guard<std::mutex> lock(send_buffer_mutuex);; //加锁
    memcpy(SendBuff,packet,len);
}
