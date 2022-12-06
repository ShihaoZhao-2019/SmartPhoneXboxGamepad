#pragma once
#include "Communication/TransCOM.h"
#include <mutex>

class TransTCP :
    public TransCOM
{
public:
    TransTCP(ULONG ip, WORD port);
    int Receive() override;
    const PUINT8 GetReceiveMessege();
    //std::mutex& GetReceiveBuffMutex();
    std::mutex* GetPReceiveBuffMutex();
    ~TransTCP() override;
private:
    bool init(ULONG ip, WORD port) override;
private:
    ULONG object_ip;
    WORD object_port;

    std::mutex receive_buff_mutex;




};

