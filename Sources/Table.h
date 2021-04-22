#pragma once
#include "../BaseElement/Object.h"
#include "Symbol.h"
#include <unordered_map>
#include <string>
#include <stack>

class SymbolTable {
public:
    SymbolTable() = default;
    void CreateVariable(const Symbol& symbol);
    void Put(const Symbol& symbol, std::shared_ptr<Object> value);
    Symbol GetSymbol(const std::string& name);


    std::shared_ptr<Object> Get(const Symbol& symbol);
    void BeginScope();
    void EndScope();
private:
    std::unordered_map<std::string, Symbol> names_;
    std::unordered_map<Symbol, std::stack<std::shared_ptr<Object>>> values_;
    std::stack<Symbol> stack_;
};