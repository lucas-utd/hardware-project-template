#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <string>

#include "SensorSample.h"
#include "SamplePacket.h"
#include "uuidUtil.h"
#include "HardwareDevice.h"

using namespace std::chrono_literals;


int main()
{
	srand(time(NULL));
	std::vector<std::unique_ptr<Hardware::HardwareDevice>> devices;
	std::vector<std::unique_ptr<Consumer::Client>> clients;

	for (int i = 0; i < 10; ++i)
	{
		int m = 1 + rand() % 5;
		int a = rand() % (m + 1);
		int g = rand() % (a + 1);
		int interval = (i % 3 == 0) ? 1 : ((i % 3 == 1) ? 2 : 3);
		interval = (interval == 1) ? 1 : (interval == 2) ? 0.5
														 : 0.33;
		devices.push_back(std::make_unique<Hardware::HardwareDevice>(m, a, g, (int)(interval * 1000)));
	}

	for (int i = 0; i < 5; ++i)
	{
		clients.push_back(std::make_unique<Consumer:: Client>("Client_" + std::to_string(i)));
	}

	// register devices to clients randomly
	for (auto &client : clients)
	{
		for (int j = 0; j < 3; ++j)
		{
			int idx = rand() % devices.size();
			devices[idx]->register_client(client.get());
		}
	}

	std::this_thread::sleep_for(10s); // simulate 10 seconds
	return 0;
}
