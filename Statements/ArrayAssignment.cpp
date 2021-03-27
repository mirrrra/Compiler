#include "ArrayAssignment.h"

void ArrayAssignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}