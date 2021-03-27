#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"

class ReturnStatement: public Statement{
public:
    ReturnStatement(Expression* return_value): return_value_(return_value) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* return_value_;
};