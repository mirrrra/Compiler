#include "IntExpression.h"

void IntExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}