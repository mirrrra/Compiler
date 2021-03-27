#pragma once
#include "Expression.h"
#include <string>
#include "../driver.h"

class LenExpression: public Expression{
public:
    LenExpression(Driver* driver, const std::string& id)
        : driver_(driver), id_(id) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    std::string id_;
};