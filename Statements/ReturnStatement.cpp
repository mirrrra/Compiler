#include "ReturnStatement.h"

void ReturnStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}