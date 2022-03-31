#include "ExpressionList.h"

void ExpressionList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

ExpressionList::ExpressionList(Expression *first) {
    expr_seq_.push_back(first);
}

void ExpressionList::push_front(Expression *value) {
    expr_seq_.push_front(value);
}