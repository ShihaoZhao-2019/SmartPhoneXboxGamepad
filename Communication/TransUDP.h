#pragma once
#include "TransCOM.h"



class TransUDP :
    public TransCOM
{
public:
    TransUDP(UINT port);
    const SOCKADDR_IN& GetClientMessege() ;
    int Receive() override;
    int Send(HANDLE packet) override;
    ~TransUDP() override;

private:
    bool init(ULONG ip, WORD port) override;
    void PraseData() override;
    void UpdateSendBuff(HANDLE packet) override;
private:
    bool bOpt;
    SOCKADDR_IN client_messege;
    PSOCKADDR_IN p_client_messege;


};

