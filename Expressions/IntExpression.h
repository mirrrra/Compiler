#pragma once
#include "Expression.h"

class IntExpression: public Expression{
public:
    IntExpression(int value): value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    int value_;
};