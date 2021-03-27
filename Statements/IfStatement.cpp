#include "IfStatement.h"

void IfStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}