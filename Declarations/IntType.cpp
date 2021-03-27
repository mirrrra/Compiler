#include "IntType.h"

void IntType::Accept(Visitor* visitor) {
    visitor->Visit(this);
}