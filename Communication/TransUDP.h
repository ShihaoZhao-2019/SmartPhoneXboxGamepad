#pragma once
#include "TransCOM.h"


class TransUDP :
    public TransCOM
{
public:
    TransUDP(UINT port);
    const SOCKADDR_IN& GetClientMessege() ;

private:
    bool init(UINT port) override;
    void PraseData() override;
    void UpdateSendBuff(COMMON_MESSEGE_HANDLE* packet) override;
    ~TransUDP() override;
private:
    bool bOpt;
    SOCKADDR_IN client_messege;
    PSOCKADDR_IN p_client_messege;


};

