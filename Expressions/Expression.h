#pragma once
#include "../Statements/Statement.h"

class Expression: public Statement{
public:
    virtual void Accept(Visitor* visitor) = 0;
};