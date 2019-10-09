#pragma once

#include <string>

struct Message {
    std::string data;
    unsigned long long timestamp;

    Message(std::string data) : data(std::move(data)) {}
    Message(const char* data_) : data(data_) {}
};

bool inline operator<(const Message& a, const Message& b) {
    return a.timestamp > b.timestamp;
}

