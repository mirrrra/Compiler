#include "VoidType.h"

void VoidType::Accept(Visitor* visitor) {
    visitor->Visit(this);
}