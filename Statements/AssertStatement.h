#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"

class AssertStatement: public Statement{
public:
    AssertStatement(Expression* message): message_(message) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* message_;
};