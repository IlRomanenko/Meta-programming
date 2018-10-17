#include "Observer.h"

void Observer::notify() {
    for (const auto& upper : listeners) {
        upper->processEvent(Event("notify"));
    }
}
