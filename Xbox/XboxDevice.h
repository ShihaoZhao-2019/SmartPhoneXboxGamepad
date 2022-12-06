#pragma once
#define WIN32_LEAN_AND_MEAN

//some header file
#include <windows.h>
#include <Xinput.h>
#include <ViGEm/Client.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <objbase.h>
#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>

//some Macro Definition
#define XUSER_MAX_COUNT			1

//class Definition
class XboxDevice
{
public:
	XboxDevice();
	void init();
	void ReceiveXboxState(std::mutex* xbox_state_mutex,const uint8_t* packet);
	//set it is a static function,in order to std::thread
	static void CycleUpdateXboxState(std::mutex* xbox_state_mutex, XboxDevice *self);
	~XboxDevice();
	


private:
	void ResetGamepads();
	bool UpdateXboxState();

public:

private:
	//Defines an alias representing a target device object
	PVIGEM_TARGET pad;
	//Defines an alias representing a driver connection object.
	PVIGEM_CLIENT client;
	//Define xbox state;
	XINPUT_STATE state;
	PXINPUT_STATE p_state;


};