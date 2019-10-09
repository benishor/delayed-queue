#pragma once

#include "Message.h"
#include <vector>
#include <queue>
#include <mutex>

class DelayedQueue {
public:
    void offer(Message message);
    void offerWithDelay(Message message, unsigned long delayInMilliseconds);
    std::vector<Message> take();

private:
    std::priority_queue<Message> priorityQueue;
    std::mutex queueMutex;
};

