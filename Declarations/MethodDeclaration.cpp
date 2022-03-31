#include "MethodDeclaration.h"

void MethodDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}