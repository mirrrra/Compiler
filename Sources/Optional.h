#pragma once
#include <utility>

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
    T& value();
    explicit operator bool () const;
    bool has_value() const;
private:
    T value_;
    bool initialized_;
};