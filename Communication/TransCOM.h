#pragma once
#include <WinSock2.h>
#include <stdio.h>

#define COMMON_MESSEGE_HANDLE	void *

#define	MAX_SEND_BUF_LEN			32
#define MAX_RECEIVE_BUF_LEN			MAX_SEND_BUF_LEN*2


class TransCOM
{

public:
	virtual int Send(COMMON_MESSEGE_HANDLE* packet);
	virtual int Receive();

protected:
	TransCOM();
	virtual bool init(UINT port) = 0;
	virtual ~TransCOM();

	virtual void UpdateSendBuff(COMMON_MESSEGE_HANDLE* packet) = 0;
	virtual void PraseData() = 0;

protected:
	////about api
	//WORD wVersionRequested;
	//WSADATA wsaData;

	SOCKET connect_socket;

	//about addr
	//my addr
	SOCKADDR_IN sin;
	//others addr
	SOCKADDR_IN sin_from;

	//about messege
	INT8 SendBuff[MAX_SEND_BUF_LEN];
	INT8 ReceiveBuff[MAX_RECEIVE_BUF_LEN];
	int nAddeLen;

};

