#pragma once


#include "Intermediate.h"
#include "Base.h"

template <int COUNT>
class Mediator : public Intermediate<intermediate::types::Mediator> {

    std::array<std::shared_ptr<Base>, COUNT> instances;
public:

    Mediator() {
        for (int i = 0; i < COUNT; i++) {
            instances[i] = std::make_shared<Base>();
        }
    }

    void request() override {
        for (const auto& instance : instances) {
            if (!instance->isBusy()) {
                instance->baseMethod();
                std::cout << "Found available" << std::endl;
                return;
            }
        }
        std::cout << "All busy" << std::endl;
    }
};