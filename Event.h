#pragma once

#include <string>

class Event {

    std::string message;
public:

    Event(std::string event_message) : message(event_message) {}

    std::string GetMessage() const {
        return message;
    }
};