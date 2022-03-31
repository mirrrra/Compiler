#include "IdExpression.h"

void IdExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void ArrayIdExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}