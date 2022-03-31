#pragma once
#include "Expression.h"

class BoolExpression: public Expression{
public:
    BoolExpression(bool value): value_(value) {}
    virtual void Accept(Visitor* visitor) override;

    bool value_;
};