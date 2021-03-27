#include "BoolExpression.h"

void BoolExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}