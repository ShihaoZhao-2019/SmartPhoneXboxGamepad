#pragma once
#include <stdio.h>
#include <QtGlobal>
#include <QSharedPointer>
#include <iostream>
#include <mutex>
#include <memory.h>

#define	MAX_SEND_BUF_LEN			32
#define MAX_RECEIVE_BUF_LEN			MAX_SEND_BUF_LEN*2


class TransCOM:
        public QObject
{


public:
    virtual int Send(void *  packet);
	virtual int Receive();

protected:
    TransCOM();
	virtual ~TransCOM();

    virtual void UpdateSendBuff(void * packet);
	virtual void PraseData();

protected:

	//about messege
    qint8 SendBuff[MAX_SEND_BUF_LEN];
    qint8 ReceiveBuff[MAX_RECEIVE_BUF_LEN];

};

