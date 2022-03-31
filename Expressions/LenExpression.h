#pragma once
#include "Expression.h"
#include <string>
#include "../driver.h"

class LenExpression: public Expression{
public:
    LenExpression(const std::string& id)
        : id_(id) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
};