#pragma once
#include "Object.h"

class IntObject: public Object {
public:
    explicit IntObject(int value): value_(value) {}
    virtual bool ToBool() const override;
    virtual int ToInt() const override;
protected:
    int value_;
};