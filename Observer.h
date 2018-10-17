#pragma once

#include <set>
#include "Upper.h"
#include "Intermediate.h"
#include "Event.h"

template<typename T>
class Upper;

class Observer : public Intermediate<intermediate::types::Observer> {

    using inter_type = intermediate::types::Observer;

    std::set<Upper<inter_type>* > listeners;

    std::shared_ptr<Base> instance;

    void notify();

public:

    Observer() {
        instance = std::make_shared<Base>();
    }

    void request() override {
        instance->baseMethod();
        notify();
    }

    void subscribe(Upper<inter_type>* listener) {
        listeners.insert(listener);
    }

    void unsubscribe(Upper<inter_type>* listener) {
        listeners.erase(listener);
    }
};