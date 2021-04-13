#pragma once
#include "Expression.h"
#include "../Declarations/Type.h"
#include "../driver.h"
#include <string>

class NewExpression: public Expression{
public:
    NewExpression(Type* type): type_id_(type) {}
    virtual void Accept(Visitor* visitor) override;

    Type* type_id_;
};

class ArrayNewExpression: public Expression{
public:
    ArrayNewExpression(const std::string& id, Type* type, Expression* len_expr)
        : id_(id), type_id_(type), len_expr_(len_expr) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    Type* type_id_;
    Expression* len_expr_;
};