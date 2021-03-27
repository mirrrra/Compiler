#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include <string>

class FieldAssignment: public Statement{
public:
    FieldAssignment(Expression* id, Expression* value)
            : id_(id), value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* id_;
    Expression* value_;
};