#include "program.h"

void Program::Accept(Visitor* visitor) {
    visitor->Visit(this);
}