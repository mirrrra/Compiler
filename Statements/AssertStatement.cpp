#include "AssertStatement.h"

void AssertStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}