#include "DeclarationList.h"

void DeclarationList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

DeclarationList::DeclarationList(Declaration *first) {
    decl_seq_.push_back(first);
}

void DeclarationList::push_front(Declaration *value) {
    decl_seq_.push_front(value);
}