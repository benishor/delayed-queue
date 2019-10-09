#include "DelayedQueue.h"
#include "Dispatcher.h"

int main() {
    DelayedQueue delayedQueue{};
    delayedQueue.offer("Message 1");
    delayedQueue.offerWithDelay("Message 2", 1000);
    delayedQueue.offer("Message 3");
    delayedQueue.offerWithDelay("STOP", 2000);

    Dispatcher dispatcher{delayedQueue};
    dispatcher.waitForFinish();

    return 0;
}
