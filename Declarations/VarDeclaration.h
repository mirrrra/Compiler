#pragma once
#include "Declaration.h"
#include "Type.h"
#include "../driver.h"
#include <string>

class VarDeclaration: public Declaration{
public:
    VarDeclaration(Type* type, const std::string& id): type_(type), id_(id) {}
    virtual void Accept(Visitor* visitor) override;

    Type* type_;
    std::string id_;
};