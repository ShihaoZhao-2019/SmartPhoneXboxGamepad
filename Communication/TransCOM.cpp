#include "TransCOM.h"

TransCOM::TransCOM()
{
    nAddeLen = sizeof(SOCKADDR);
}


int TransCOM::Send(COMMON_MESSEGE_HANDLE* packet)
{
    UpdateSendBuff(packet);
    const int nSendSize = sendto(connect_socket, (char *)SendBuff, MAX_SEND_BUF_LEN, 0, (SOCKADDR*)&sin, nAddeLen);
    return nSendSize;
}

int TransCOM::Receive()
{
    const int nReceiveSize = recvfrom(connect_socket, (char*)ReceiveBuff, MAX_RECEIVE_BUF_LEN, 0, (SOCKADDR*)&sin_from, &nAddeLen);
    PraseData();
    //printf("%x\n", sin_from.sin_addr.s_addr);
    //printf("%d\n", sin_from.sin_port);
    return nReceiveSize;
}

TransCOM::~TransCOM()
{
}

