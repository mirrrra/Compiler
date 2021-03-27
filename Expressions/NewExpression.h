#pragma once
#include "Expression.h"
#include "../Declarations/Type.h"
#include "../driver.h"

class NewExpression: public Expression{
public:
    NewExpression(Driver* driver, Type* type): driver_(driver), type_id_(type) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    Type* type_id_;
};

class ArrayNewExpression: public Expression{
public:
    ArrayNewExpression(Driver* driver, Type* type, Expression* len_expr)
        : driver_(driver), type_id_(type), len_expr_(len_expr) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    Type* type_id_;
    Expression* len_expr_;
};