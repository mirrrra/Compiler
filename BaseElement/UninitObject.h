#pragma once
#include "Object.h"

class UninitObject: public Object {
public:
    virtual int ToInt() const override;
    virtual bool ToBool() const override;
};