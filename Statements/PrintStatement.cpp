#include "PrintStatement.h"

void PrintStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}