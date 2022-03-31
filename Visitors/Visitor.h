#pragma once
#include "ForwardDeclarations.h"

class Visitor {
public:
    virtual void Visit(Program* program) = 0;
    virtual void Visit(BoolExpression* expression) = 0;
    virtual void Visit(ExpressionList* list) = 0;
    virtual void Visit(ArrayIdExpression* expression) = 0;
    virtual void Visit(IdExpression* expression) = 0;
    virtual void Visit(IntExpression* expression) = 0;
    virtual void Visit(LenExpression* expression) = 0;
    virtual void Visit(MethodCall* method_call) = 0;
    virtual void Visit(NewExpression* expression) = 0;
    virtual void Visit(ArrayNewExpression* expression) = 0;
    virtual void Visit(BinaryOpExpression* expression) = 0;
    virtual void Visit(UnaryOpExpression* expression) = 0;

    virtual void Visit(ArrayAssignment* assignment) = 0;
    virtual void Visit(AssertStatement* assignment) = 0;
    virtual void Visit(FieldAssignment* assignment) = 0;
    virtual void Visit(FieldArrayAssignment* assignment) = 0;
    virtual void Visit(IfStatement* statement) = 0;
    virtual void Visit(PrintStatement* statement) = 0;
    virtual void Visit(ReturnStatement* statement) = 0;
    virtual void Visit(SimpleAssignment* statement) = 0;
    virtual void Visit(WhileStatement* statement) = 0;
    virtual void Visit(StatementList* list) = 0;

    virtual void Visit(ClassDeclaration* decl) = 0;
    virtual void Visit(ClassDeclarationList* list) = 0;
    virtual void Visit(DeclarationList* list) = 0;
    virtual void Visit(MainClassDeclaration* decl) = 0;
    virtual void Visit(MethodDeclaration* decl) = 0;
    virtual void Visit(VarDeclaration* decl) = 0;
    virtual void Visit(ArrayType* type) = 0;
    virtual void Visit(IdType* type) = 0;
    virtual void Visit(BoolType* type) = 0;
    virtual void Visit(IntType* type) = 0;
    virtual void Visit(VoidType* type) = 0;
};