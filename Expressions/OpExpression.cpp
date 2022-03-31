#include "OpExpression.h"

void BinaryOpExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void UnaryOpExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}