#include "Client.h"

namespace Consumer
{
    Client::Client(std::string id)
    : id_(id)
    , isStop_(false)
    {
        consumer_ = std::thread([this]()
                                { this->consume(); });
    }

    Client::~Client()
    {
        isStop_ = true;
        cv_.notify_all();
        if (consumer_.joinable())
            consumer_.join();
    }

    void Client::receive(const Models::SamplePacket &packet)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(packet);
        cv_.notify_one();
    }

    void Client::consume()
    {
        while (!isStop_)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [&]()
                        { return !queue_.empty() || isStop_; });
            while (!queue_.empty())
            {
                auto packet = queue_.front();
                queue_.pop();
                lock.unlock();
                std::printf("Client %s received sample from %s\n", id_.c_str(), packet.uuid.c_str());
                lock.lock();
            }
        }
    }
    
} // namespace Consumer

