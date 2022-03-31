#pragma once
#include "Visitor.h"
#include <fstream>
#include <string>
#include "VisitorsIncludes.h"

class PrintVisitor: public Visitor{
public:
    explicit PrintVisitor(const std::string& filename): stream_(filename) {}
    ~PrintVisitor() { stream_.close(); };

    virtual void Visit(Program* program) override;
    virtual void Visit(BoolExpression* expression) override;
    virtual void Visit(ExpressionList* list) override;
    virtual void Visit(ArrayIdExpression* expression) override;
    virtual void Visit(IdExpression* expression) override;
    virtual void Visit(IntExpression* expression) override;
    virtual void Visit(LenExpression* expression) override;
    virtual void Visit(MethodCall* method_call) override;
    virtual void Visit(NewExpression* expression) override;
    virtual void Visit(ArrayNewExpression* expression) override;
    virtual void Visit(BinaryOpExpression* expression) override;
    virtual void Visit(UnaryOpExpression* expression) override;

    virtual void Visit(ArrayAssignment* assignment) override;
    virtual void Visit(AssertStatement* statement) override;
    virtual void Visit(FieldAssignment* assignment) override;
    virtual void Visit(FieldArrayAssignment* assignment) override;
    virtual void Visit(IfStatement* statement) override;
    virtual void Visit(PrintStatement* statement) override;
    virtual void Visit(ReturnStatement* statement) override;
    virtual void Visit(SimpleAssignment* assignment) override;
    virtual void Visit(WhileStatement* statement) override;
    virtual void Visit(StatementList* list) override;

    virtual void Visit(ClassDeclaration* decl) override;
    virtual void Visit(ClassDeclarationList* list) override;
    virtual void Visit(DeclarationList* list) override;
    virtual void Visit(MainClassDeclaration* decl) override;
    virtual void Visit(MethodDeclaration* decl) override;
    virtual void Visit(VarDeclaration* decl) override;
    virtual void Visit(ArrayType* type) override;
    virtual void Visit(IdType* type) override;
    virtual void Visit(BoolType* type) override;
    virtual void Visit(IntType* type) override;
    virtual void Visit(VoidType* type) override;

private:
    void PrintTabs();
    std::ofstream stream_;
    int num_tabs_{0};
};