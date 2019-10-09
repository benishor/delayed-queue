#include "DelayedQueue.h"
#include "Timer.h"

void DelayedQueue::offer(Message message) {
    message.timestamp = Timer::currentMicroseconds();
    std::lock_guard<std::mutex> guard(queueMutex);
    priorityQueue.push(message);
}

void DelayedQueue::offerWithDelay(Message message, unsigned long delayInMilliseconds) {
    message.timestamp = Timer::currentMicroseconds() + delayInMilliseconds * 1000UL;
    std::lock_guard<std::mutex> guard(queueMutex);
    priorityQueue.push(message);
}

std::vector<Message> DelayedQueue::take() {
    std::lock_guard<std::mutex> guard(queueMutex);
    if (priorityQueue.empty()) return {};

    unsigned long now = Timer::currentMicroseconds();
    std::vector<Message> result{};
    while (!priorityQueue.empty()) {
        auto topMessage = priorityQueue.top();
        if (topMessage.timestamp <= now) {
            result.push_back(topMessage);
            priorityQueue.pop();
        } else {
            break;
        }
    }
    return result;
}

