#include "TransTCP.h"
#include <iostream>
TransTCP::TransTCP(ULONG ip, WORD port)
{
	object_ip = ip;
	object_port = port;
	bool success = init(ip, port);
	if (success == FALSE)delete[] this;
		
}

int TransTCP::Receive()
{
	std::lock_guard<std::mutex> lock(receive_buff_mutex); //lock
	const int len = recv(connect_socket,(char *)ReceiveBuff, MAX_RECEIVE_BUF_LEN, 0);
	//ReceiveBuff[len] = '\0';
	//std::cout<<"len:"<<len<<"messege:"<< ReceiveBuff<<std::endl;
	return len;
}

const PUINT8 TransTCP::GetReceiveMessege()
{
	return (PUINT8)ReceiveBuff;
}

std::mutex* TransTCP::GetPReceiveBuffMutex()
{
	// TODO: 在此处插入 return 语句
	return &receive_buff_mutex;
}

bool TransTCP::init(ULONG ip, WORD port)
{
	sin_from.sin_family = AF_INET;
	sin_from.sin_port = htons(port);
	sin_from.sin_addr.S_un.S_addr = htonl(ip);

	connect_socket = socket(AF_INET, SOCK_STREAM,0);
	if (SOCKET_ERROR == connect_socket) {
		printf("Socket() error:%d", WSAGetLastError());
		return FALSE;
	}
	if (connect(connect_socket, (SOCKADDR*)&sin_from, nInAddeLen) == INVALID_SOCKET) {
		printf("连接失败:%d", WSAGetLastError());
		return FALSE;
	}
	return TRUE;
}


TransTCP::~TransTCP()
{
}
