#include "Table.h"
#include <iostream>

void SymbolTable::CreateVariable(const Symbol& symbol) {
    std::cerr << "Creating variable " << symbol.GetName() << std::endl;
    if (values_.find(symbol) == values_.end()) {
        values_[symbol] = std::stack<std::shared_ptr<Object>>();
    }

    // ааааа, зачем? это что-то еще не созданное int x; int x;?
    values_[symbol].push(std::make_shared<UninitObject>());
}

void SymbolTable::Put(const Symbol& symbol, std::shared_ptr<Object> value) {
    std::cout << "Put " << symbol.GetName() << " value " << value->ToInt() << std::endl;
    if (values_.find(symbol) == values_.end()) {
        throw std::runtime_error(symbol.GetName() +  ": variable not declared");
    }

    values_[symbol].pop();
    values_[symbol].push(value);
    stack_.push(symbol);
}

Symbol SymbolTable::GetSymbol(const std::string &name) {
    auto it = names_.find(name);
    if (it != names_.end()) {
        return it->second;
    }

    Symbol symbol(name);
    names_.insert({name, symbol});
    return symbol;
}

std::shared_ptr<Object> SymbolTable::Get(const Symbol& symbol) {
    return std::shared_ptr<Object>();
}

void SymbolTable::BeginScope() {
    stack_.push(Symbol("{"));
}

void SymbolTable::EndScope() {
    while (stack_.top() != Symbol("{")) {
        Symbol symbol = stack_.top();

        std::cerr << "Popping " << symbol.GetName() << std::endl;

        values_[symbol].pop();
        if (values_[symbol].empty()) {
            values_.erase(symbol);
        }
        stack_.pop();
    }
    stack_.pop();
}
