#pragma once
#include "Expression.h"
#include "ExpressionList.h"
#include "../driver.h"
#include <string>
#include "../Sources/Optional.h"

class MethodCall: public Expression{
public:
    MethodCall(Driver* driver, const std::string& id, const std::string& where):
        driver_(driver), id_(id), where_(where) {}
    MethodCall(Driver* driver, const std::string& id, const std::string& where, ExpressionList* args):
            driver_(driver), id_(id), where_(where), args_(args) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    std::string id_;
    std::string where_;
    Optional<ExpressionList*> args_;
};