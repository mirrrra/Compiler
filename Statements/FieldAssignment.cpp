#include "FieldAssignment.h"

void FieldAssignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void FieldArrayAssignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}