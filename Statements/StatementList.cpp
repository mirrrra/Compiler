#include "StatementList.h"

void StatementList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void StatementList::push_front(Statement *value) {
    stmt_seq_.push_front(value);
}