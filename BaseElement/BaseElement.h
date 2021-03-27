#pragma once
#include "../Visitors/Visitor.h"
#include "../Visitors/PrintVisitor.h"

class BaseElement{
public:
    virtual void Accept(Visitor* visitor) = 0; // visitor добавить
};