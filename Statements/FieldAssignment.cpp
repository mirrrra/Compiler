#include "FieldAssignment.h"

void FieldAssignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}