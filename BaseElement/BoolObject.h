#pragma once
#include "Object.h"

class BoolObject: public Object {
public:
    explicit BoolObject(bool value): value_(value) {}
    virtual bool ToBool() const override;
    virtual int ToInt() const override;
protected:
    bool value_;
};