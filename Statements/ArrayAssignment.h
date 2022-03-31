#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include <string>

class ArrayAssignment: public Statement{
public:
    ArrayAssignment(const std::string& id, Expression* index, Expression* value)
            : id_(id), index_(index), value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    Expression* index_;
    Expression* value_;
};