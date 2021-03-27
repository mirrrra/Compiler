#pragma once
#include "../BaseElement/BaseElement.h"

class Type: public BaseElement{
public:
    virtual void Accept(Visitor* visitor) = 0;
};
