#pragma once

#include "Intermediate.h"

class Proxy : public Intermediate<intermediate::types::Proxy> {
    std::shared_ptr<Base> instance;

public:

    Proxy() {
        instance = std::make_shared<Base>();
    }

    void request() override {
        instance->baseMethod();
    }
};