#pragma once
#include "Type.h"

class BoolType: public Type{
public:
    virtual void Accept(Visitor* visitor) override;
};