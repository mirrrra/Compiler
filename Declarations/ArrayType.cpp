#include "ArrayType.h"

void ArrayType::Accept(Visitor* visitor) {
    visitor->Visit(this);
}