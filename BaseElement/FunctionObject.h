#pragma once
#include "Object.h"
#include <vector>

class FunctionObject: public Object {
public:
    virtual bool IsMain() const override;
    virtual bool IsFunction() const override;
private:
    bool is_main_{false};
    std::vector<Object*> args_;

};