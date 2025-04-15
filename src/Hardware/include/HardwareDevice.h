#pragma once

#include "SensorSample.h"
#include "SamplePacket.h"
#include "uuidUtil.h"
#include "Client.h"
#include "AlgorithmInstance.h"

namespace Hardware
{
    class HardwareDevice
    {
    public:
        HardwareDevice(int magnetometers, int accelerometers, int gyroscopes, int interval_ms);
        ~HardwareDevice();

    public:
        void register_client(Consumer::Client *client);
        void unregister_client(Consumer::Client *client);

    private:
        void run();
        Models::SensorSample random_sample();

    private:
        std::string uuid_;
        int magnetometers_, accelerometers_, gyroscopes_;
        int interval_ms_;
        std::vector<Algo::AlgorithmInstance> algorithms_;
        std::thread thread_;
        std::atomic<bool> isStop_;
        std::vector<Consumer::Client *> clients_;
        std::mutex clients_mutex_;
    };
}