#pragma once
#include "../Statements/Statement.h"

class Declaration: public Statement {
public:
    virtual void Accept(Visitor* visitor) = 0;
};