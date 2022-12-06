#include "TransCOM.h"

int TransCOM::Send(HANDLE  packet)
{
    return 0;
}

int TransCOM::Receive()
{
    return 0;
}

TransCOM::TransCOM()
{
    nAddeLen = sizeof(SOCKADDR);
    nInAddeLen = sizeof(SOCKADDR_IN);
}

bool TransCOM::init(ULONG ip, WORD port)
{
    return false;
}


TransCOM::~TransCOM()
{
}

void TransCOM::UpdateSendBuff(HANDLE  packet)
{
}

void TransCOM::PraseData()
{
}

