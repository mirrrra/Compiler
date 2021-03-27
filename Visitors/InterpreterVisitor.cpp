#include "InterpreterVisitor.h"
#include <cassert>

const size_t MAGIC_SIZE = 1024;

void InterpreterVisitor::Visit(Program *program) {
    program->main_class_->Accept(this);
}

void InterpreterVisitor::Visit(BoolExpression *expression) {
    SetCurrentValue(expression->value_);
}

void InterpreterVisitor::Visit(ExpressionList *list) {
    // do nothing
}

void InterpreterVisitor::Visit(ArrayIdExpression *expression) {
    assert(array_variables_.find(expression->id_) != array_variables_.end());
    expression->index_->Accept(this);

    int value = GetCurrentValue();
    assert(array_variables_[expression->id_].size() <= value);
    SetCurrentValue(array_variables_[expression->id_][value]);
}

void InterpreterVisitor::Visit(IdExpression *expression) {
    assert(variables_.find(expression->id_) != variables_.end());
    SetCurrentValue(variables_[expression->id_]);
}

void InterpreterVisitor::Visit(IntExpression *expression) {
    SetCurrentValue(expression->value_);
}

void InterpreterVisitor::Visit(LenExpression *expression) {
    assert(array_variables_.find(expression->id_) != array_variables_.end());
    SetCurrentValue(array_variables_[expression->id_].size());
}

void InterpreterVisitor::Visit(MethodCall *method_call) {
    // do nothing
}

void InterpreterVisitor::Visit(NewExpression *expression) {
    SetCurrentValue(0);
}

void InterpreterVisitor::Visit(ArrayNewExpression *expression) {
    // do nothing
}

void InterpreterVisitor::Visit(BinaryOpExpression *expression) {
    expression->first_->Accept(this);
    int first_value = GetCurrentValue();
    expression->second_->Accept(this);
    int second_value = GetCurrentValue();

    switch (expression->op_) {
        case '&':
            first_value = first_value && second_value;
            break;
        case '|':
            first_value = first_value || second_value;
            break;
        case '<':
            first_value = first_value < second_value;
            break;
        case '>':
            first_value = first_value > second_value;
            break;
        case '=':
            first_value = first_value == second_value;
            break;
        case '+':
            first_value = first_value + second_value;
            break;
        case '-':
            first_value = first_value - second_value;
            break;
        case '*':
            first_value = first_value * second_value;
            break;
        case '/':
            first_value = first_value / second_value;
            break;
        case '%':
            first_value = first_value % second_value;
            break;
    }

    SetCurrentValue(first_value);
}

void InterpreterVisitor::Visit(UnaryOpExpression *expression) {
    expression->first_->Accept(this);
    SetCurrentValue(!GetCurrentValue());
}

void InterpreterVisitor::Visit(ArrayAssignment *assignment) {
    assert(array_variables_.find(assignment->id_) != array_variables_.end());

    assignment->index_->Accept(this);
    int index = GetCurrentValue();
    assert(array_variables_[assignment->id_].size() <= index);

    assignment->value_->Accept(this);
    int value = GetCurrentValue();
    array_variables_[assignment->id_][index] = value;
}

void InterpreterVisitor::Visit(AssertStatement *assignment) {
    assignment->message_->Accept(this);
    assert(GetCurrentValue());
}

void InterpreterVisitor::Visit(FieldAssignment *statement) {
    assert(variables_.find(statement->id_) != variables_.end());
    statement->value_->Accept(this);
    int value = GetCurrentValue();
    variables_[statement->id_] = value;
}

void InterpreterVisitor::Visit(FieldArrayAssignment *statement) {
    assert(variables_.find(statement->id_) != variables_.end());
    statement->index_->Accept(this);
    int index = GetCurrentValue();
    assert(array_variables_[statement->id_].size() <= index);

    statement->index_->Accept(this);
    int value = GetCurrentValue();
    array_variables_[statement->id_][index] = value;
}

void InterpreterVisitor::Visit(IfStatement *statement) {
    statement->condition_->Accept(this);
    int value = GetCurrentValue();
    if (value) {
        statement->then_actions_->Accept(this);
    } else {
        if (statement->else_actions_) {
            statement->else_actions_.value()->Accept(this);
        }
    }
}

void InterpreterVisitor::Visit(PrintStatement *statement) {
    statement->print_value_->Accept(this);
    std::cout << GetCurrentValue() << std::endl;
}

void InterpreterVisitor::Visit(ReturnStatement *statement) {
    // do nothing
}

void InterpreterVisitor::Visit(SimpleAssignment *assignment) {
    assert(variables_.find(assignment->id_) != variables_.end());
    assignment->value_->Accept(this);
    int value = GetCurrentValue();
    variables_[assignment->id_] = value;
}

void InterpreterVisitor::Visit(WhileStatement *statement) {
    statement->condition_->Accept(this);
    int value = GetCurrentValue();
    while (value) {
        statement->actions_->Accept(this);
        statement->condition_->Accept(this);
        value = GetCurrentValue();
    }
}

void InterpreterVisitor::Visit(StatementList *list) {
    for (Statement* stmt: list->stmt_seq_) {
        stmt->Accept(this);
    }
}

void InterpreterVisitor::Visit(ClassDeclaration *decl) {
    // do nothing
}

void InterpreterVisitor::Visit(ClassDeclarationList *list) {
    // do nothing
}

void InterpreterVisitor::Visit(DeclarationList *list) {
    // do nothing
}

void InterpreterVisitor::Visit(MainClassDeclaration *decl) {
    decl->actions_->Accept(this);
}

void InterpreterVisitor::Visit(MethodDeclaration *decl) {
    // do nothing
}

void InterpreterVisitor::Visit(VarDeclaration *decl) {
    std::string id = decl->id_;
    assert(variables_.find(id) == variables_.end());
    assert(array_variables_.find(id) == array_variables_.end());

    decl->type_->Accept(this);
    int current_type = GetCurrentValue();
    switch(current_type) {
        case TYPE::TYPE_BOOL:
        case TYPE::TYPE_INT:
            variables_[id] = 0;
            break;
        case TYPE::TYPE_ARRAY_OF_BOOL:
        case TYPE::TYPE_ARRAY_OF_INT:
            array_variables_[id] = std::vector<int>(MAGIC_SIZE);
            break;
    }
}

void InterpreterVisitor::Visit(ArrayType *type) {
    type->type_->Accept(this);
    int current_type = GetCurrentValue();
    if (current_type == TYPE::TYPE_BOOL) {
        SetCurrentValue(TYPE::TYPE_ARRAY_OF_BOOL);
    } else {
        SetCurrentValue(TYPE::TYPE_ARRAY_OF_INT);
    }

}

void InterpreterVisitor::Visit(IdType *type) {
    // do nothing
}

void InterpreterVisitor::Visit(BoolType *type) {
    SetCurrentValue(TYPE::TYPE_BOOL);
}

void InterpreterVisitor::Visit(IntType *type) {
    SetCurrentValue(TYPE::TYPE_INT);
}

void InterpreterVisitor::Visit(VoidType *type) {
    SetCurrentValue(TYPE::TYPE_VOID);
}

void InterpreterVisitor::SetCurrentValue(int value) {
    current_value_ = value;
}

int InterpreterVisitor::GetCurrentValue() const {
    return current_value_;
}


