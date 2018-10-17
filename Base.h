#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include <random>
#include <type_traits>

class Base {

    std::chrono::steady_clock::time_point expired;
public:

    Base() {
        expired = std::chrono::steady_clock::now();
    }

    void baseMethod() {
        std::cout << "Base class" << std::endl;
        expired = std::chrono::steady_clock::now() + std::chrono::milliseconds(std::default_random_engine()());
    }

    bool isBusy() const {
        return std::chrono::steady_clock::now() < expired;
    }
};

