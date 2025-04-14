#include "Client.h"

namespace Consumer
{
    Client::Client(std::string id)
    : id_(id)
    , stop_(false)
    {
        consumer_ = std::thread([this]()
                                { this->consume(); });
    }

    Client::~Client()
    {
        stop_ = true;
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
        while (!stop_)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [&]()
                        { return !queue_.empty() || stop_; });
            while (!queue_.empty())
            {
                auto packet = queue_.front();
                queue_.pop();
                lock.unlock();
                std::cout << "Client " << id_ << " received sample from " << packet.uuid << "\n";
                lock.lock();
            }
        }
    }
    
} // namespace Consumer

