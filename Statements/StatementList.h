#pragma once
#include "Statement.h"
#include <list>

class StatementList: public Statement{
public:
    StatementList() {}
    void push_front(Statement* value);
    virtual void Accept(Visitor* visitor) override;

    std::list<Statement*> stmt_seq_;
};