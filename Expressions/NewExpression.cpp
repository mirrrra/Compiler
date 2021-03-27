#include "NewExpression.h"

void NewExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void ArrayNewExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}