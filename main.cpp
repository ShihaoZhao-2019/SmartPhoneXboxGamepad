#include<Transfer/MessegeTransfer.h>

int main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("��ʼ��Winsockʧ��");
		return 0;
	}

	MessTrans* p = new MessTrans();
	p->TaskContorl();
}


