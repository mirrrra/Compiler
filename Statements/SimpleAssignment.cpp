#include "SimpleAssignment.h"

void SimpleAssignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}