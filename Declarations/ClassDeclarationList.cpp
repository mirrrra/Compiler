#include "ClassDeclarationList.h"

void ClassDeclarationList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

void ClassDeclarationList::push_front(ClassDeclaration *class_) {
    class_decl_seq_.push_front(class_);
}