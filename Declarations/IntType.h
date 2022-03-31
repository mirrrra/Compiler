#pragma once
#include "Type.h"

class IntType: public Type{
public:
    virtual void Accept(Visitor* visitor) override;
};