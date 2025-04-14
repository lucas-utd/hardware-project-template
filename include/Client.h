#pragma once

#include <string>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>

#include "SamplePacket.h"

namespace Consumer
{
    class Client
    {
    public:
        Client(std::string id);

        ~Client();

    public:
        void receive(const Models::SamplePacket &packet);

    private:
        void consume();

    private:
        std::string id_;
        std::thread consumer_;
        std::queue<Models::SamplePacket> queue_;
        std::mutex mutex_;
        std::condition_variable cv_;
        std::atomic<bool> isStop_;
    };
} // namespace Consumer

