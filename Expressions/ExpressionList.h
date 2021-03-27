#pragma once
#include "Expression.h"
#include "../BaseElement/BaseElement.h"
#include <list>

class ExpressionList: public Expression{
public:
    ExpressionList(Expression* first);
    void push_front(Expression* value);
    virtual void Accept(Visitor* visitor) override;

    std::list<Expression*> expr_seq_;
};