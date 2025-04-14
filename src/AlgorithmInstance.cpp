#include "AlgorithmInstance.h"

#include <thread>
#include <chrono>

namespace Algo
{
	AlgorithmInstance::AlgorithmInstance(int id)
		: algorithmId_(id)
		, generator_(std::random_device{}()) // Seed the random number generator
		, distFactor_(0.5f, 2.0f) // Initialize the random number generator
	{
	}

	void AlgorithmInstance::processSampleAsync(Models:: SensorSample sample, std::function<void(Models::Pose)> callback) {
        std::thread([this, sample, callback]() {
            Models::Pose result = this->processSample(sample);
            callback(result);  // Pass result back to whoever called
        }).detach(); // Detach since we're managing result via callback
    }

	Models::Pose AlgorithmInstance::processSample(const Models::SensorSample& sample)
	{
		 // Simulate variable processing time (e.g., 0.5x to 2x interval)
		 double factor = distFactor_(generator_);
		 int sleepMs = static_cast<int>(samplingIntervalMs * factor);
		 std::this_thread::sleep_for(std::chrono::milliseconds(sleepMs));
 
		 Models::Pose pose{sample.x, sample.y, sample.z, 0.0f, 0.0f, 0.0f, 1.0f}; // Dummy pose data
		 return pose;
	}
} // namespace Algo

