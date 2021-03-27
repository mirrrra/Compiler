#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include <string>

class FieldAssignment: public Statement{
public:
    FieldAssignment(const std::string& id, Expression* value)
            : id_(id), value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    Expression* value_;
};

class FieldArrayAssignment: public Statement{
public:
    FieldArrayAssignment(const std::string& id, Expression* index, Expression* value)
            : id_(id), index_(index), value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    Expression* index_;
    Expression* value_;
};