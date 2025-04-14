#pragma once

#include "SensorSample.h"

namespace Algo
{
    class AlgorithmInstance
    {
    public:
        AlgorithmInstance() = default;
    public:
        void process(Models::SensorSample sample, std::vector<float> &pose, int interval_ms);
    };
} // namespace Algo
