#pragma once
#include "Expression.h"

class BinaryOpExpression: public Expression{
public:
    BinaryOpExpression(char op, Expression* first, Expression* second)
        :op_(op), first_(first), second_(second) {}
    virtual void Accept(Visitor* visitor) override;

    char op_;
    Expression* first_;
    Expression* second_;
};

class UnaryOpExpression: public Expression{
public:
    UnaryOpExpression(char op, Expression* first)
            :op_(op), first_(first) {}
    virtual void Accept(Visitor* visitor) override;

    char op_;
    Expression* first_;
};