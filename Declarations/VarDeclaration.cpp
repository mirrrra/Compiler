#include "VarDeclaration.h"

void VarDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}