#include "TransUDP.h"
#include <assert.h>


TransUDP::TransUDP(UINT port) 
{
	init(port);
}


const SOCKADDR_IN& TransUDP::GetClientMessege()
{
	// TODO: 在此处插入 return 语句
	return client_messege;
	
}



bool TransUDP::init(UINT port)
{
	//init socket
	connect_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == connect_socket)
	{
		const int err = WSAGetLastError();
		printf("socket error!error code is % d\n", err);
		return 0;
	}

	//init addr -- my addr
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = 0;
	//init addr -- other addr
	sin_from.sin_family = AF_INET;
	sin_from.sin_port = htons(port);
	sin_from.sin_addr.s_addr = INADDR_BROADCAST;//INADDR_BROADCAST = 255.255.255.255 express broadcast addr

	bOpt = true;
	setsockopt(connect_socket, SOL_SOCKET, SO_BROADCAST, (char*)&bOpt, sizeof(bOpt));
	auto err = bind(connect_socket, (SOCKADDR*)&sin, sizeof(SOCKADDR));
	if (SOCKET_ERROR == err)
	{
		err = WSAGetLastError();
		printf("bind error!error code is % d / n", err);
		return 0;
	}

	p_client_messege = &client_messege;
}

void TransUDP::PraseData()
{
	memcpy(p_client_messege,ReceiveBuff, nAddeLen);
}

void TransUDP::UpdateSendBuff(COMMON_MESSEGE_HANDLE* packet)
{

}

TransUDP::~TransUDP()
{
}
