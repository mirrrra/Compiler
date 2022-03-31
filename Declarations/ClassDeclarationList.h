#pragma once
#include "ClassDeclaration.h"
#include <list>

class ClassDeclarationList: public Declaration{
public:
    ClassDeclarationList() = default;
    void push_front(ClassDeclaration* class_);
    virtual void Accept(Visitor* visitor) override;

    std::list<ClassDeclaration*> class_decl_seq_;
};