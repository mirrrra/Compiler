#include "UninitObject.h"

int UninitObject::ToInt() const {
    throw std::runtime_error("Variable not initialized");
}

bool UninitObject::ToBool() const {
    throw std::runtime_error("Variable not initialized");
}
