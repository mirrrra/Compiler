#pragma once
#include "Expression.h"
#include "../driver.h"
#include <string>

class IdExpression: public Expression{
public:
    IdExpression(Driver* driver, const std::string& id, bool is_global)
        : driver_(driver), id_(id), is_global_(is_global) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    std::string id_;
    bool is_global_;
};

class ArrayIdExpression: public Expression{
public:
    ArrayIdExpression(Driver* driver, const std::string& id, Expression* index, bool is_global)
            : driver_(driver), id_(id), index_(index), is_global_(is_global) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    std::string id_;
    Expression* index_;
    bool is_global_;
};
