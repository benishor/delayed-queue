#include "Dispatcher.h"
#include "Timer.h"
#include <thread>
#include <iostream>

Dispatcher::Dispatcher(DelayedQueue& delayedQueue_) : delayedQueue(delayedQueue_) {
    startConsumer();
}

void Dispatcher::waitForFinish() {
    worker.join();
}

void Dispatcher::startConsumer() {
    worker = std::thread([this]() {
        bool stopWorker = false;
        auto startTime = Timer::currentMicroseconds();
        do {
            for (const auto& message : delayedQueue.take()) {
                auto relativeTime = (Timer::currentMicroseconds() - startTime) / 1000;
                std::cout << "Received message [" << message.data << "] at time [" << relativeTime << "]ms"
                          << std::endl;
                if (message.data == "STOP") {
                    stopWorker = true;
                }
            }
        } while (!stopWorker);
    });

}
