#pragma once
#include "Declaration.h"
#include "Type.h"
#include "../driver.h"
#include <string>

class VarDeclaration: public Declaration{
public:
    VarDeclaration(Driver* driver, Type* type, const std::string& id): driver_(driver), type_(type), id_(id) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    Type* type_;
    std::string id_;
};