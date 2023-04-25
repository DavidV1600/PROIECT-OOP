#pragma once
#include <exception>
#include <string>

class Exceptie_Custom : public std::exception {
public:
    const char* what() const noexcept override {
        return "Ai o eroare baiatu!\n";
    }
};
