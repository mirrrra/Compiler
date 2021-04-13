#pragma once
#include "Declaration.h"
#include <string>
#include "../driver.h"
#include "../Statements/StatementList.h"

class MainClassDeclaration: public Declaration{
public:
    MainClassDeclaration(const std::string& id, StatementList* actions)
            :id_(id), actions_(actions) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
    StatementList* actions_;
};