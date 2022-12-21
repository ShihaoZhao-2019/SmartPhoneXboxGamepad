#include<XboxDevice.h>

XboxDevice::XboxDevice()
{
	//Initializes the COM library on the current threadand identifies the concurrency model as single - thread apartment(STA).
	init();

}

void XboxDevice::init()
{
	CoInitialize(NULL);
	//init Member variable
	//Allocates an object representing a driver connection. return A new driver connection object.
	client = vigem_alloc();
	assert(client != nullptr);
	printf("Success to setup ViGEmClient.\n");
	printf("Connecting to ViGEm driver...\n");
	//connect client to bus
	const auto connectResult = vigem_connect(client);
	if (!VIGEM_SUCCESS(connectResult))
	{
		printf("ViGEm Bus connection failed with error code 0x%08X.\n", connectResult);
		vigem_free(client);
		assert(VIGEM_SUCCESS(connectResult));
		delete this;
	}
	
	pad = vigem_target_x360_alloc();
	//connect  one device to client 
	const auto targetAddResult = vigem_target_add(client, pad);
	if (VIGEM_SUCCESS(targetAddResult))
	{
		printf("Connected new gamepad.\n");
	}
	else
	{
		vigem_target_free(pad);
		printf("Failed to add pad with error code 0x%08X.\n",targetAddResult);
		assert(VIGEM_SUCCESS(targetAddResult));
		delete this;
	}
	
	p_state = &state;

}

void XboxDevice::ResetGamepads()
{
	//remove a device from bus
	vigem_target_remove(client, pad);
	//free device
	vigem_target_free(pad);
}

bool XboxDevice::UpdateXboxState()
{
	if (vigem_target_x360_update(client, pad, *reinterpret_cast<XUSB_REPORT*>(&p_state->Gamepad)) != VIGEM_ERROR_NONE)
	{
		return FALSE;
	}
	return TRUE;
}


void OutputwButtons(PXINPUT_GAMEPAD p_xbox_state)
{
	for (int i = 15; i >= 0; i--)
	{
		printf("bit%d:%d\n", 15 - i, p_xbox_state->wButtons & 1 << i ? 1 : 0);
	}
}
void MyPrint(PXINPUT_GAMEPAD p)
{
	printf("Lx:%d\n", p->sThumbLX);
	printf("Ly:%d\n", p->sThumbLY);
	printf("Rx:%d\n", p->sThumbRX);
	printf("Ry:%d\n", p->sThumbRY);

	OutputwButtons(p);
}


void XboxDevice::ReceiveXboxState(std::mutex* xbox_state_mutex ,const uint8_t* packet)
{
	std::lock_guard<std::mutex> lock(*xbox_state_mutex);
	memcpy(p_state, packet, sizeof(XINPUT_STATE));
	//MyPrint(&p_state->Gamepad);
}

void XboxDevice::CycleUpdateXboxState(std::mutex* xbox_state_mutex, XboxDevice* self)
{
	while (true)
	{
		xbox_state_mutex->lock();
		if (self->UpdateXboxState() == FALSE)
		{
			printf("update xbox state Failed");
		}
		xbox_state_mutex->unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); //µ•Œª «∫¡√Î
	}
}

XboxDevice::~XboxDevice()
{
	ResetGamepads();
	vigem_free(client);
	vigem_target_free(pad);
}



