#include "HardwareDevice.h"
#include "Client.h"

namespace Hardware
{
    HardwareDevice::HardwareDevice(int magnetometers, int accelerometers, int gyroscopes, int interval_ms)
        : uuid_(std::move(Utils::generate_uuid()))
        , magnetometers_(magnetometers)
        , accelerometers_(accelerometers)
        , gyroscopes_(gyroscopes)
        , interval_ms_(interval_ms)
        , isStop_(false)
    {
        for (int i = 0; i < magnetometers_; ++i)
        {
            algorithms_.emplace_back(i);
        }
        thread_ = std::thread([this]()
                                { this->run(); });
    }

    HardwareDevice::~HardwareDevice()
    {
        isStop_ = true;
        if (thread_.joinable())
            thread_.join();
    }

    void HardwareDevice::register_client(Consumer::Client *client)
    {
        std::unique_lock<std::mutex> lock(clients_mutex_);
        clients_.push_back(client);
    }

    void HardwareDevice::unregister_client(Consumer::Client *client)
    {
        std::unique_lock<std::mutex> lock(clients_mutex_);
        clients_.erase(std::remove(clients_.begin(), clients_.end(), client), clients_.end());
    }


    void HardwareDevice::run()
    {
        while (!isStop_)
        {
            Models::SamplePacket packet;
            packet.uuid = uuid_;
            packet.timestamp = std::chrono::steady_clock::now();
            // generate samples
            for (int i = 0; i < magnetometers_; ++i)
                packet.magnetometers.push_back(random_sample());
            for (int i = 0; i < accelerometers_; ++i)
                packet.accelerometers.push_back(random_sample());
            for (int i = 0; i < gyroscopes_; ++i)
                packet.gyroscopes.push_back(random_sample());
            // process with algorithms
            for (int i = 0; i < magnetometers_; ++i)
            {
                std::vector<float> pose;
                // process asynchronously
                algorithms_[i].processSampleAsync(packet.magnetometers[i], [this, &packet, i](Models::Pose pose)
                {
                    std::unique_lock<std::mutex> lock(clients_mutex_);
                    packet.poses.push_back({pose.x, pose.y, pose.z, pose.qx, pose.qy, pose.qz, pose.qw});
                });
            }
            // distribute to clients
            std::unique_lock<std::mutex> lock(clients_mutex_);
            for (auto *client : clients_)
            {
                client->receive(packet);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms_));
        }
    }

    Models::SensorSample HardwareDevice::random_sample()
    {
        return {(float)(rand() % 100) / 10.0f, (float)(rand() % 100) / 10.0f, (float)(rand() % 100) / 10.0f};
    }
} // namespace Hardware

