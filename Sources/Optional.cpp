#include "Optional.h"
#include <stdexcept>

template<typename T>
T& Optional<T>::operator*() {
    return value();
}

template<typename T>
T& Optional<T>::value() {
    if (!initialized_) {
        throw std::runtime_error("Uninitialized value in Optional!");
    }
    return value_;
}

template<typename T>
Optional<T>::operator bool() const {
    return has_value();
}

template<typename T>
bool Optional<T>::has_value() const {
    return initialized_;
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional &other) {
    initialized_ = other.initialized_;
    value_ = other.value_;
}

template<typename T>
Optional<T>& Optional<T>::operator=(Optional &&other) noexcept {
    initialized_ = other.initialized_;
    value_ = std::move(other.value_);
}
