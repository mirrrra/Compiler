#include "IdType.h"

void IdType::Accept(Visitor* visitor) {
    visitor->Visit(this);
}