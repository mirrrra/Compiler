#pragma once
#include "../BaseElement/BaseElement.h"

class Statement: public BaseElement {
public:
    virtual void Accept(Visitor* visitor) = 0;
};