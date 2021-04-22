#include "Symbol.h"

std::string Symbol::GetName() const {
    return name_;
}

bool Symbol::operator==(const Symbol &symbol) {
    return name_ == symbol.name_;
}

bool Symbol::operator!=(const Symbol &symbol) {
    return name_ != symbol.name_;
}

