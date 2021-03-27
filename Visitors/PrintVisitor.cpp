#include "PrintVisitor.h"

void PrintVisitor::Visit(Program *program) {
    stream_ << "Program:" << std::endl;

    ++num_tabs_;

    program->main_class_->Accept(this);
    program->classes_->Accept(this);

    --num_tabs_;
}

void PrintVisitor::Visit(BoolExpression *expression) {
    PrintTabs();
    stream_ << "BoolExpression: " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(ExpressionList *list) {
    PrintTabs();
    stream_ << "ExpressionList: " << std::endl;

    ++num_tabs_;
    for (Expression* expr: list->expr_seq_) {
        expr->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(ArrayIdExpression *expression) {
    PrintTabs();
    stream_ << "ArrayIdExpression: " << expression->id_ << std::endl;
    ++num_tabs_;
    expression->index_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(IdExpression *expression) {
    PrintTabs();
    stream_ << "IdExpression: " << expression->id_ << std::endl;
}

void PrintVisitor::Visit(IntExpression *expression) {
    PrintTabs();
    stream_ << "IntExpression: " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(LenExpression *expression) {
    PrintTabs();
    stream_ << "LenExpression: " << expression->id_ << std::endl;
}

void PrintVisitor::Visit(MethodCall *method_call) {
    PrintTabs();
    stream_ << "MethodCall: " << method_call->id_ << " In class: " << method_call->where_;
    if (method_call->args_) {
        stream_ << " With args: " << std::endl;
        num_tabs_++;
        method_call->args_.value()->Accept(this);
        num_tabs_--;
        return;
    }
    stream_ << std::endl;
}

void PrintVisitor::Visit(NewExpression *expression) {
    PrintTabs();
    stream_ << "NewExpression: " << std::endl;
    num_tabs_++;
    expression->type_id_->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(ArrayNewExpression *expression) {
    PrintTabs();
    stream_ << "ArrayNewExpression: " << std::endl;
    num_tabs_++;
    expression->type_id_->Accept(this);
    expression->len_expr_->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(BinaryOpExpression *expression) {
    PrintTabs();
    stream_ << "BinaryOpExpression: " << "operator " << expression->op_ << std::endl;
    ++num_tabs_;
    expression->first_->Accept(this);
    expression->second_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(UnaryOpExpression *expression) {
    PrintTabs();
    stream_ << "UnaryOpExpression: " << " Operator: " << expression->op_ << std::endl;
    ++num_tabs_;
    expression->first_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(ArrayAssignment *assignment) {
    PrintTabs();
    stream_ << "ArrayAssignment: " << assignment->id_ << std::endl;
    ++num_tabs_;

    PrintTabs();
    stream_ << "Index: " << std::endl;
    assignment->index_->Accept(this);

    PrintTabs();
    stream_ << "Value: " << std::endl;
    assignment->value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(AssertStatement *statement) {
    PrintTabs();
    stream_ << "AssertStatement: " << std::endl;
    ++num_tabs_;
    statement->message_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(FieldAssignment *assignment) {
    PrintTabs();
    stream_ << "FieldAssignment: " << assignment->id_ << std::endl;
    ++num_tabs_;
    assignment->value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(FieldArrayAssignment *assignment) {
    PrintTabs();
    stream_ << "FieldArrayAssignment: " << assignment->id_ << std::endl;
    ++num_tabs_;
    PrintTabs();
    stream_ << "Index: " << std::endl;
    assignment->index_->Accept(this);

    PrintTabs();
    stream_ << "Value: " << std::endl;
    assignment->value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(IfStatement *statement) {
    PrintTabs();
    stream_ << "IfStatement: " << std::endl;
    ++num_tabs_;
    statement->condition_->Accept(this);
    PrintTabs();
    stream_ << "Then: " << std::endl;
    statement->then_actions_->Accept(this);
    if (statement->else_actions_) {
        PrintTabs();
        stream_ << "Else: " << std::endl;
        statement->else_actions_.value()->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(PrintStatement *statement) {
    PrintTabs();
    stream_ << "PrintStatement: " << std::endl;
    ++num_tabs_;
    statement->print_value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(ReturnStatement *statement) {
    PrintTabs();
    stream_ << "ReturnStatement: " << std::endl;
    ++num_tabs_;
    statement->return_value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(SimpleAssignment *assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->id_ << std::endl;
    ++num_tabs_;
    assignment->value_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(WhileStatement *statement) {
    PrintTabs();
    stream_ << "WhileStatement: " << std::endl;
    ++num_tabs_;
    statement->condition_->Accept(this);
    statement->actions_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(StatementList *list) {
    PrintTabs();
    stream_ << "StatementList: " << std::endl;

    ++num_tabs_;
    for (Statement* stmt: list->stmt_seq_) {
        stmt->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(ClassDeclaration *decl) {
    PrintTabs();
    stream_ << "ClassDeclaration: " << decl->id_;
    if (decl->parent_id_) {
        PrintTabs();
        stream_ << " Extends: " << decl->parent_id_.value();
    }
    stream_ << std::endl;

    ++num_tabs_;
    decl->declarations_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(ClassDeclarationList *list) {
    PrintTabs();
    stream_ << "ClassDeclarationList: " << std::endl;

    ++num_tabs_;
    for (ClassDeclaration* class_decl: list->class_decl_seq_) {
        class_decl->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(DeclarationList *list) {
    PrintTabs();
    stream_ << "DeclarationList: " << std::endl;

    ++num_tabs_;
    for (Declaration* decl: list->decl_seq_) {
        decl->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(MainClassDeclaration *decl) {
    PrintTabs();
    stream_ << "MainClassDeclaration: " << decl->id_<< std::endl;

    ++num_tabs_;
    decl->actions_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(MethodDeclaration *decl) {
    PrintTabs();
    stream_ << "MethodDeclaration: " << decl->id_ << " With return type: " << std::endl;
    num_tabs_++;
    decl->type_->Accept(this);
    num_tabs_--;
    if (decl->declarations_) {
        PrintTabs();
        stream_ << " With args: " << std::endl;
        num_tabs_++;
        decl->declarations_.value()->Accept(this);
        num_tabs_--;
    }
    num_tabs_++;
    decl->actions_->Accept(this);
    num_tabs_--;
    stream_ << std::endl;
}

void PrintVisitor::Visit(VarDeclaration *decl) {
    PrintTabs();
    stream_ << "VarDeclaration: " << decl->id_ << " With type:  " << std::endl;
    num_tabs_++;
    decl->type_->Accept(this);
    num_tabs_--;
}

void PrintVisitor::Visit(ArrayType *type) {
    PrintTabs();
    stream_ << "ArrayType: "<< std::endl;
    ++num_tabs_;
    type->type_->Accept(this);
    --num_tabs_;

}

void PrintVisitor::Visit(IdType *type) {
    PrintTabs();
    stream_ << "IdType: "<< type->id_ << std::endl;
}

void PrintVisitor::Visit(BoolType *type) {
    PrintTabs();
    stream_ << "BoolType: "<< std::endl;
}

void PrintVisitor::Visit(IntType *type) {
    PrintTabs();
    stream_ << "IntType: "<< std::endl;
}

void PrintVisitor::Visit(VoidType *type) {
    PrintTabs();
    stream_ << "VoidType: "<< std::endl;
}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}


