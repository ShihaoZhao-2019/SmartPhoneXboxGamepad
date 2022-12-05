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

//some Macro Definition
#define XUSER_MAX_COUNT			1

//class Definition
class XboxDevice
{
public:
	XboxDevice();
	void init();

private:
	void ResetGamepads();
	bool UpdateXboxState();
	void ReceiveXboxState(const uint8_t* packet);
	~XboxDevice();

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