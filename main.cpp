#include "DelayedQueue.h"
#include "Dispatcher.h"

int main() {
    DelayedQueue delayedQueue{};
    Dispatcher dispatcher{delayedQueue};


    for (int i = 0; i < 20; i++) {
        delayedQueue.offerWithDelay("Message " + std::to_string(i), i*100);
    }
//    delayedQueue.offerWithDelay("Message 2", 1000);
//    delayedQueue.offer("Message 3");
    delayedQueue.offerWithDelay("STOP", 2000);

    dispatcher.waitForFinish();

    return 0;
}
