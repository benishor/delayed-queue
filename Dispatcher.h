#pragma once

#include <thread>
#include "DelayedQueue.h"

class Dispatcher {
public:
    explicit Dispatcher(DelayedQueue& delayedQueue_);
    void waitForFinish();
private:
    DelayedQueue& delayedQueue;
    std::thread worker;
    void startConsumer();
};
