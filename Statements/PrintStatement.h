#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"

class PrintStatement: public Statement{
public:
    PrintStatement(Expression* print_value): print_value_(print_value) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* print_value_;
};