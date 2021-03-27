#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include <string>

class SimpleAssignment: public Statement{
public:
    SimpleAssignment(const std::string& id, Expression* value)
            : id_(id), value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    Expression* value_;
};