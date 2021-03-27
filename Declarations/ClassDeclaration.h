#pragma once
#include "Declaration.h"
#include "../driver.h"
#include <string>
#include "DeclarationList.h"
#include "../Sources/Optional.h"

class ClassDeclaration: public Declaration{
public:
    ClassDeclaration(Driver* driver, const std::string& id, DeclarationList* declarations)
        :driver_(driver), id_(id), declarations_(declarations) {}
    ClassDeclaration(Driver* driver, const std::string& id, const std::string& pid, DeclarationList* declarations)
            :driver_(driver), id_(id), parent_id_(pid), declarations_(declarations) {}
    virtual void Accept(Visitor* visitor) override;

    Driver* driver_;
    std::string id_;
    Optional<std::string> parent_id_;
    DeclarationList* declarations_;
};