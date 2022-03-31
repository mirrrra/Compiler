#include "LenExpression.h"

void LenExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}