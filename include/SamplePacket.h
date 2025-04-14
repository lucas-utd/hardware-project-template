#pragma once
#include <chrono>
#include <vector>
#include <string>

#include "SensorSample.h"


namespace Models
{
    struct SamplePacket
    {
        std::string uuid;
        std::chrono::steady_clock::time_point timestamp;
        std::vector<SensorSample> magnetometers;
        std::vector<SensorSample> accelerometers;
        std::vector<SensorSample> gyroscopes;
        std::vector<std::vector<float>> poses; // One per magnetometer
    };
} // namespace Models
