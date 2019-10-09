#include "DelayedQueue.h"
#include "Timer.h"

void DelayedQueue::offer(Message message) {
    message.timestamp = Timer::currentMicroseconds();
    priorityQueue.push(message);
}

void DelayedQueue::offerWithDelay(Message message, unsigned long delayInMilliseconds) {
    message.timestamp = Timer::currentMicroseconds() + delayInMilliseconds * 1000UL;
    priorityQueue.push(message);
}

std::vector<Message> DelayedQueue::take() {
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

