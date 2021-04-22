#pragma once
#include "Object.h"

class ArrayObject: public Object {
public:
    virtual bool IsArray() const override;
protected:
};