#pragma once
#include "Declaration.h"
#include <list>

class DeclarationList: public Declaration{
public:
    DeclarationList(Declaration* first);
    void push_front(Declaration* value);
    virtual void Accept(Visitor* visitor) override;
    std::list<Declaration*> decl_seq_;
};