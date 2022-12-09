#include<Transfer/MessegeTransfer.h>

int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("³õÊ¼»¯WinsockÊ§°Ü");
		return 0;
	}

	MessTrans* p = new MessTrans();
	p->TaskContorl();
}


