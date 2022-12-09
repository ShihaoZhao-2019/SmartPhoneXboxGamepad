#include<Communication/TransUDP.h>

TransUDP::TransUDP()
{
    local_ip_address = GetLocalIpAddress();
    local_ip_address_int = IPtoINT(local_ip_address.toStdString());
    my_udp_socket = QSharedPointer<QUdpSocket>(new QUdpSocket());
}

int TransUDP::Send()
{
    UpdateSendBuff();
    return my_udp_socket.get()->writeDatagram((char*)SendBuff,sizeof(unsigned int)+sizeof(unsigned short),QHostAddress::Broadcast,UDP_PORT);
}

TransUDP::~TransUDP()
{

}

QString &TransUDP::GetLocalHost()
{
    return local_ip_address;
}

unsigned int &TransUDP::GetLocalHostInt()
{
    return local_ip_address_int;
}

void TransUDP::SetTCPPort(unsigned short port)
{
    tcp_port = port;
}

unsigned short &TransUDP::GetTCPPort()
{
    return tcp_port;
}


void TransUDP::UpdateSendBuff()
{
    memcpy(SendBuff,&local_ip_address_int,sizeof(unsigned int));
    memcpy(SendBuff+sizeof(unsigned int),&tcp_port,sizeof(unsigned short));
}

QString TransUDP::GetLocalIpAddress()
{
    QString ip_address;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
        {
            ip_address = ipAddressesList.at(i).toString();
        }
    }
    if (ip_address.isEmpty())
    {
        ip_address = QHostAddress(QHostAddress::LocalHost).toString();
    }
    return ip_address;
}

unsigned int TransUDP::IPtoINT(const std::string & strIP)
{
    unsigned int nRet = 0;

    char chBuf[16] = "";
    memcpy(chBuf, strIP.c_str(),15);

    char* szBuf = strtok(chBuf,_IP_MARK);

    int i = 0;//计数
    while(NULL != szBuf)//取一个
    {
        nRet += atoi(szBuf)<<((3-i)*8);
        szBuf = strtok(NULL,_IP_MARK);
        i++;
    }
    return nRet;
}

