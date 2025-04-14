#include "AlgorithmInstance.h"

#include <thread>

namespace Algo
{
	void AlgorithmInstance::process(Models::SensorSample sample, std::vector<float> &pose, int interval_ms)
	{
		int base = interval_ms / 2;
		int max = interval_ms * 2;
		int delay = base + (rand() % (max - base + 1));
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		pose = {1.0f, 0.0f, 0.0f, 0.0f, sample.x, sample.y, sample.z};
	}
} // namespace Algo

