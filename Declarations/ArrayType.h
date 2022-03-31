#pragma once
#include "Type.h"

class ArrayType: public Type{
public:
    explicit ArrayType(Type* type): type_(type) {}
    virtual void Accept(Visitor* visitor) override;

    Type* type_;
};