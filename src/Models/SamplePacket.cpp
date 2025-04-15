#include "SamplePacket.h"

#include <chrono>
#include <vector>
#include <string>
#include <iostream>


namespace Models
{
    // Constructor
    SamplePacket::SamplePacket(const std::string& uuid)
        : uuid(uuid)
        , timestamp(std::chrono::steady_clock::now())
        , magnetometers()
        , accelerometers()
        , gyroscopes()
        , poses()
        {}

    // Destructor
    SamplePacket::~SamplePacket() {}
} // namespace Models