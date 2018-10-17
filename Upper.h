#pragma once

#include <memory>
#include <type_traits>
#include "Intermediate.h"
#include "Event.h"
#include "Observer.h"

template <typename Kind>
class Upper {

    std::shared_ptr<Intermediate<Kind>> intermediate;
public:

    Upper(const std::shared_ptr<Intermediate<Kind>>& instance) : intermediate(instance) { }

    void request() {
        intermediate->request();
    }

    void processEvent(const Event& event) {
        std::cout << event.GetMessage() << std::endl;
    }
};