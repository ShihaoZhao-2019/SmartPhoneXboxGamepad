#include<iostream>
#include<XboxDevice.h>
#include <chrono>
#include <thread>
int main()
{
	XboxDevice *one_device = new XboxDevice();
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1)); //µ•Œª «∫¡√Î
	}
	return 0;
}

