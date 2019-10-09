#include "Timer.h"
#include <chrono>

unsigned long long Timer::currentMicroseconds() {
    std::chrono::microseconds micros = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    return micros.count();
}

