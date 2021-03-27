#pragma once

#include "BaseElement/BaseElement.h"
#include "Declarations/ClassDeclarationList.h"
#include "Declarations/MainClassDeclaration.h"

class Program: public BaseElement {
public:
    Program(MainClassDeclaration* main_class, ClassDeclarationList* classes)
        : main_class_(main_class), classes_(classes) {}
    virtual void Accept(Visitor* visitor) override;

    MainClassDeclaration* main_class_;
    ClassDeclarationList* classes_;
};
