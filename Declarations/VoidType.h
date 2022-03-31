#pragma once
#include "Type.h"

class VoidType: public Type{
public:
    virtual void Accept(Visitor* visitor) override;
};