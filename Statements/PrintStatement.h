#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include "../Sources/Optional.h"

class PrintStatement: public Statement{
public:
    PrintStatement() {}
    PrintStatement(Expression* print_value): print_value_(print_value) {}
    virtual void Accept(Visitor* visitor) override;

    Optional<Expression*> print_value_;
};