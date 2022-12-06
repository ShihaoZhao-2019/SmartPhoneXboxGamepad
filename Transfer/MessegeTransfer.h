#pragma once
#include<Communication/TransTCP.h>
#include<Communication/TransUDP.h>
#include<xbox/XboxDevice.h>
#include<memory>
#include <thread>

//Nothing special, just my birthday
#define UDP_PORT		1998

class MessTrans
{
public:
	MessTrans();
	~MessTrans();
	void TaskContorl();
private:
	std::shared_ptr<TransTCP> BuildTcpConnect();
	bool init();

private:
	std::thread xbox_thread;
	//some object ,use Smart pointer to manage
	std::shared_ptr<TransTCP> share_p_tcp_client;
	std::shared_ptr<TransUDP> share_p_udp_client;
	std::shared_ptr<XboxDevice> share_p_xbox_device;

	bool xbox_thread_start_flag;
};
