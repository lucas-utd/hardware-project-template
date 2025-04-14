#pragma once

#include <vector>
#include <random>
#include <functional>

#include "SensorSample.h"
#include "Pose.h"

namespace Algo
{
    class AlgorithmInstance
    {
    public:
        AlgorithmInstance(int id);
    public:
        void processSampleAsync(Models::SensorSample sample, std::function<void(Models::Pose)> callback);

    private:
        Models::Pose processSample(const Models::SensorSample& sample);

    private:
        int algorithmId_;
        const int samplingIntervalMs = 1; // Simulated base interval
        std::mt19937 generator_;
        std::uniform_real_distribution<> distFactor_;
    };
} // namespace Algo
