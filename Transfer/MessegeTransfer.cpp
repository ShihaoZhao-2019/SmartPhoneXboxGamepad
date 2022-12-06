#include "MessegeTransfer.h"

MessTrans::MessTrans()
{
	if (init() == FALSE)
	{
		printf("init default!");
		delete[] this;
	}
}

MessTrans::~MessTrans()
{
}

void MessTrans::TaskContorl()
{
	share_p_tcp_client = BuildTcpConnect();
	if (share_p_tcp_client.get() == nullptr)
	{
		printf("tcp connect failed\n");
		return;
	}
	//// free udp
	//share_p_udp_client = nullptr;
	// build xbox device
	share_p_xbox_device = std::make_shared<XboxDevice>();
	
	while(share_p_tcp_client.get()->Receive()>0)
	{
		share_p_xbox_device.get()->ReceiveXboxState(share_p_tcp_client.get()->GetPReceiveBuffMutex(),share_p_tcp_client.get()->GetReceiveMessege());
		//1ms update xbox state
		if (xbox_thread_start_flag == FALSE)
		{
			xbox_thread = std::thread(share_p_xbox_device.get()->CycleUpdateXboxState, share_p_tcp_client.get()->GetPReceiveBuffMutex() ,share_p_xbox_device.get());
			xbox_thread_start_flag = TRUE;
		}
	}
}

std::shared_ptr<TransTCP> MessTrans::BuildTcpConnect()
{
	//wait udp Wait for the server to broadcast its own IP address and Port
	while (share_p_udp_client.get()->Receive()>0)
	{
		SOCKADDR_IN tcp_messege = share_p_udp_client.get()->GetClientMessege();
		return std::make_shared<TransTCP>(tcp_messege.sin_addr.S_un.S_addr, tcp_messege.sin_port);
	}
	return nullptr;
}

bool MessTrans::init()
{
	share_p_udp_client = std::make_shared<TransUDP>(UDP_PORT);
	xbox_thread_start_flag = FALSE;
	return TRUE;
}
