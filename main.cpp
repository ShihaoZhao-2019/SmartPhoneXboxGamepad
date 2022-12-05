//#include<iostream>
//#include<XboxDevice.h>
//#include <chrono>
//#include <thread>
////int main()
////{
////	XboxDevice *one_device = new XboxDevice();
////	while (true)
////	{
////		std::this_thread::sleep_for(std::chrono::milliseconds(1)); //单位是毫秒
////	}
////	return 0;
////}
//
//int main()
//{
//
//	return 0;
//}



// 服务器端
// Server.cpp : Defines the entry point for the console application.
//

#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <Communication/TransUDP.h>
using namespace std;


const int MAX_BUF_LEN = 255;

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	// 启动socket api
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return -1;
	}

	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		return -1;
	}


	TransUDP* my_udp = new TransUDP(3779);
	SOCKADDR messege;
	while (true)
	{
		int len = my_udp->Receive();
		//printf("Receive: %x\n:::::%d\n", my_udp->GetClientMessege().sin_addr.s_addr, len);
	}

	//WORD wVersionRequested;
	//WSADATA wsaData;
	//int err;

	//// 启动socket api
	//wVersionRequested = MAKEWORD(2, 2);
	//err = WSAStartup(wVersionRequested, &wsaData);
	//if (err != 0)
	//{
	//	return -1;
	//}

	//if (LOBYTE(wsaData.wVersion) != 2 ||
	//	HIBYTE(wsaData.wVersion) != 2)
	//{
	//	WSACleanup();
	//	return -1;
	//}

	//// 创建socket
	//SOCKET connect_socket;
	//connect_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//if (INVALID_SOCKET == connect_socket)
	//{
	//	err = WSAGetLastError();
	//	//printf("/"socket / " error! error code is %d/n", err);
	//	return -1;
	//}

	//SOCKADDR_IN sin;
	//sin.sin_family = AF_INET;
	//sin.sin_port = htons(3779);
	//sin.sin_addr.s_addr = INADDR_BROADCAST;

	//bool bOpt = true;
	////设置该套接字为广播类型
	//setsockopt(connect_socket, SOL_SOCKET, SO_BROADCAST, (char*)&bOpt, sizeof(bOpt));

	//int nAddrLen = sizeof(SOCKADDR);

	//char buff[MAX_BUF_LEN] = "";
	//int nLoop = 0;
	//while (1)
	//{
	//	nLoop++;
	//	sprintf_s(buff, "%8d", nLoop);

	//	// 发送数据
	//	int nSendSize = sendto(connect_socket, buff, strlen(buff), 0, (SOCKADDR*)&sin, nAddrLen);
	//	if (SOCKET_ERROR == nSendSize)
	//	{
	//		err = WSAGetLastError();
	//		//printf("/"sendto / " error!, error code is %d/n", err);
	//		return -1;
	//	}
	//	printf("Send: %s\n", buff);
	//	Sleep(500);
	//}

	//return 0;
}

