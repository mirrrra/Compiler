#include "MainClassDeclaration.h"

void MainClassDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}