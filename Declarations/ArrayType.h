#pragma once
#include "Type.h"

class ArrayType: public Type{
public:
    ArrayType(Type* type): type_(type) {}
    virtual void Accept(Visitor* visitor) override;
    Type* type_;
};