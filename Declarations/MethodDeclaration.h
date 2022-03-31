#pragma once
#include "Declaration.h"
#include "DeclarationList.h"
#include "../Statements/StatementList.h"
#include "Type.h"
#include "../driver.h"
#include <string>
#include "../Sources/Optional.h"

class MethodDeclaration: public Declaration{
public:
    MethodDeclaration(
            Driver* driver,
            Type* type,
            const std::string& id,
            DeclarationList* declarations,
            StatementList* actions
            )
        : driver_(driver), type_(type), id_(id), declarations_(declarations), actions_(actions) {}

    MethodDeclaration(Driver* driver, Type* type, const std::string& id, StatementList* actions)
            : driver_(driver), type_(type), id_(id), actions_(actions) {}
    virtual void Accept(Visitor* visitor) override;

    Type* type_;
    std::string id_;
    Optional<DeclarationList*> declarations_;
    StatementList* actions_;
    Driver* driver_;
};