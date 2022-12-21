#pragma once
#include <WinSock2.h>
#include <stdio.h>

#define	MAX_SEND_BUF_LEN			32
#define MAX_RECEIVE_BUF_LEN			MAX_SEND_BUF_LEN


class TransCOM
{

public:
	virtual int Send(HANDLE  packet);
	virtual int Receive();

protected:
	TransCOM();
	virtual bool init(ULONG ip, WORD port) = 0;
	virtual ~TransCOM();

	virtual void UpdateSendBuff(HANDLE packet);
	virtual void PraseData();

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
	int nInAddeLen;

};

