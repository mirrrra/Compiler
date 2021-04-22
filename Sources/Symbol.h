#pragma once
#include <string>

class Symbol {
public:
    explicit Symbol(const std::string& name): name_(name) {}
    explicit Symbol(std::string&& name): name_(std::move(name)) {}

    Symbol(const Symbol& symbol) = default;
    Symbol(Symbol&& symbol) = default;

    std::string GetName() const;
    bool operator==(const Symbol& symbol);
    bool operator!=(const Symbol& symbol);

private:
    std::string name_;
};

namespace std {
    template<>
    struct hash<Symbol>
    {
        std::size_t operator()(const Symbol& other) const {
            return hash<string>()(other.GetName());
        }
    };

}