#pragma once
#include "Statement.h"
#include "../Expressions/Expression.h"
#include "../Sources/Optional.h"

class IfStatement: public Statement{
public:
    IfStatement(Expression* condition, Statement* then_actions)
            : condition_(condition), then_actions_(then_actions) {}
    IfStatement(Expression* condition, Statement* then_actions, Statement* else_actions)
        : condition_(condition), then_actions_(then_actions), else_actions_(else_actions) {}
    virtual void Accept(Visitor* visitor) override;

    Expression* condition_;
    Statement* then_actions_;
    Optional<Statement*> else_actions_;

};