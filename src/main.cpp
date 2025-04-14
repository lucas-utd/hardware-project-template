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
	// Initialize random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 20);

	// Create a vector of unique pointers to HardwareDevice and Client objects
	std::vector<std::unique_ptr<Hardware::HardwareDevice>> devices;
	std::vector<std::unique_ptr<Consumer::Client>> clients;

	for (int i = 0; i < 10; ++i)
	{
		int m = 1 + dist(gen) % 5;
		int a = dist(gen) % (m + 1);
		int g = dist(gen) % (a + 1);
		int value = (i % 3 == 0) ? 1 : ((i % 3 == 1) ? 2 : 3);
		int interval = (value == 1) ? 1000 : (value == 2) ? 500 : 330;
		devices.push_back(std::make_unique<Hardware::HardwareDevice>(m, a, g, interval));
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
			int idx = dist(gen) % devices.size();
			devices[idx]->register_client(client.get());
		}
	}

	std::this_thread::sleep_for(10s); // simulate 10 seconds
	return 0;
}
