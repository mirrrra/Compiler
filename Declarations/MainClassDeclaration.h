#pragma once
#include "Declaration.h"
#include <string>
#include "../driver.h"
#include "../Statements/StatementList.h"

class MainClassDeclaration: public Declaration{
public:
    MainClassDeclaration(Driver* driver, const std::string& id, StatementList* actions)
            :driver_(driver), id_(id), actions_(actions) {}
    virtual void Accept(Visitor* visitor) override;
    std::string id_;
    StatementList* actions_;
    Driver* driver_;
};