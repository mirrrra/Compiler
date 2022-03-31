#include "WhileStatement.h"

void WhileStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}