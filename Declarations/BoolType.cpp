#include "BoolType.h"

void BoolType::Accept(Visitor* visitor) {
    visitor->Visit(this);
}