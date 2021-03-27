#pragma once
#include <utility>
#include <stdexcept>

template<typename T>
class Optional{
public:
    Optional(): initialized_(false) {}
    explicit Optional(const T& value): value_(value), initialized_(true) {}
    explicit Optional(T&& value): value_(std::move(value)), initialized_(true) {}

    Optional(const Optional& other): value_(other.value_), initialized_(other.initialized_) {}
    Optional(Optional&& other) noexcept : value_(std::move(other.value_)), initialized_(other.initialized_) {}

    Optional& operator=(const Optional& other);
    Optional& operator=(Optional&& other) noexcept ;

    T& operator*();
    T* operator->();
    T& value();
    explicit operator bool () const;
    bool has_value() const;
private:
    T value_;
    bool initialized_;
};

template<typename T>
T& Optional<T>::operator*() {
    return value();
}

template <typename T>
T* Optional<T>::operator->() {
    return &value();
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
