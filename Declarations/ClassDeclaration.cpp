#include "ClassDeclaration.h"

void ClassDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}