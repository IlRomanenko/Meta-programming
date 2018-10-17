#pragma once
#include <vector>
#include <functional>
#include <memory>

#include "Base.h"

namespace intermediate::types {
    class Proxy;
    class Observer;
    class Mediator;
}

template<typename kind>
class Intermediate {
public:
    Intermediate() = default;

    virtual void request() = 0;
};



