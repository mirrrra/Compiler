#pragma once
#include "Expression.h"
#include "ExpressionList.h"
#include "../driver.h"
#include <string>
#include "../Sources/Optional.h"

class MethodCall: public Expression{
public:
    MethodCall(const std::string& id, const std::string& where):
        id_(id), where_(where) {}
    MethodCall(const std::string& id, const std::string& where, ExpressionList* args):
        id_(id), where_(where), args_(args) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    std::string where_;
    Optional<ExpressionList*> args_;
};