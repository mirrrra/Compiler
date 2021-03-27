#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"

class WhileStatement: public Statement{
public:
    WhileStatement(Expression* condition, Statement* actions): condition_(condition), actions_(actions) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* condition_;
    Statement* actions_;
};