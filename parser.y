%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>

    class Scanner;
    class Driver;
    class Program;

    class BoolExpression;
    class Expression;
    class ExpressionList;
    class ArrayIdExpression;
    class IdExpression;
    class IntExpression;
    class LenExpression;
    class MethodCall;
    class NewExpression;
    class ArrayNewExpression;
    class BinaryOpExpression;
    class UnaryOpExpression;

    class Statement;
    class ArrayAssignment;
    class AssertStatement;
    class FieldAssignment;
    class FieldArrayAssignment;
    class IfStatement;
    class PrintStatement;
    class ReturnStatement;
    class SimpleAssignment;
    class WhileStatement;
    class StatementList;

    class Type;
    class Declaration;
    class ClassDeclaration;
    class ClassDeclarationList;
    class DeclarationList;
    class MainClassDeclaration;
    class MethodDeclaration;
    class VarDeclaration;
    class ArrayType;
    class IdType;
    class BoolType;
    class IntType;
    class VoidType;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "program.h"
    #include "driver.h"
    #include "location.hh"
    #include "Expressions/BoolExpression.h"
    #include "Expressions/Expression.h"
    #include "Expressions/ExpressionList.h"
    #include "Expressions/IdExpression.h"
    #include "Expressions/IntExpression.h"
    #include "Expressions/LenExpression.h"
    #include "Expressions/MethodCall.h"
    #include "Expressions/NewExpression.h"
    #include "Expressions/OpExpression.h"

    #include "Statements/Statement.h"
    #include "Statements/ArrayAssignment.h"
    #include "Statements/AssertStatement.h"
    #include "Statements/FieldAssignment.h"
    #include "Statements/IfStatement.h"
    #include "Statements/PrintStatement.h"
    #include "Statements/ReturnStatement.h"
    #include "Statements/SimpleAssignment.h"
    #include "Statements/StatementList.h"
    #include "Statements/WhileStatement.h"

    #include "Declarations/Type.h"
    #include "Declarations/Declaration.h"
    #include "Declarations/ClassDeclaration.h"
    #include "Declarations/ClassDeclarationList.h"
    #include "Declarations/DeclarationList.h"
    #include "Declarations/MainClassDeclaration.h"
    #include "Declarations/MethodDeclaration.h"
    #include "Declarations/VarDeclaration.h"
    #include "Declarations/ArrayType.h"
    #include "Declarations/IdType.h"
    #include "Declarations/BoolType.h"
    #include "Declarations/IntType.h"
    #include "Declarations/VoidType.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    POINT "."
    COMMA ","
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"
    ROUND_LPAREN "("
    ROUND_RPAREN ")"
    SQUARE_LPAREN "["
    SQUARE_RPAREN "]"
    CURLY_LPAREN "{" // ???
    CURLY_RPAREN "}"
    LE "<"
    GE ">"
    EQ "=="
    AND "&&"
    OR "||"
    NOT "!"
    SEMICOLON ";"
    CLASS "class"
    PUBLIC "public"
    STATIC "static"
    VOID "void"
    INT "int"
    BOOLEAN "boolean"
    MAIN "main"
    EXTENDS "extends"
    ASSERT "assert"
    RETURN "return"
    IF "if"
    ELSE "else"
    WHILE "while"
    PRINT "print" //System.out.println...
    THIS "this"
    NEW "new"
    LENGTH "length"
    TRUE "true"
    FALSE "false"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "number"
%nterm <Program*> start
%nterm <Program*> program
%nterm <ClassDeclarationList*> class_declaration_seq
%nterm <MainClassDeclaration*> main_class
%nterm <ClassDeclaration*> class_declaration
%nterm <DeclarationList*> declarations
%nterm <Declaration*> declaration
%nterm <Declaration*> method_declaration
%nterm <Declaration*> var_declaration
%nterm <DeclarationList*> args
%nterm <Declaration*> arg
%nterm <Type*> type
%nterm <Type*> simple_type
%nterm <Type*> array_type
%nterm <Type*> type_id
%nterm <StatementList*> statements_seq
%nterm <Statement*> statement
%nterm <Expression*> method_invocation
%nterm <Expression*> field_invocation
%nterm <ExpressionList*> expression_seq
%nterm <Statement*> assignment
%nterm <Expression*> expression
%nterm <Expression*> binary_expression

//%printer { yyo << $$; } <*>;

%%
%start start;
start:
    program { $$ = $1; driver.program = $$; };

program:
    main_class class_declaration_seq { $$ = new Program($1, $2); };

class_declaration_seq:
    %empty { $$ = new ClassDeclarationList(); }
    | class_declaration class_declaration_seq { $2->push_front($1); $$ = $2; };

main_class:
    "class" "id" "{" "public" "static" "void" "main" "(" ")" "{" statements_seq "}" "}" {
        $$ = new MainClassDeclaration(&driver, $2, $11); };

class_declaration:
    "class" "id" "{" declarations "}" { $$ = new ClassDeclaration(&driver, $2, $4); }
    | "class" "id" "extends" "id" "{" declarations "}" { $$ = new ClassDeclaration(&driver, $2, $4, $6); };

declarations:
    declaration { $$ = new DeclarationList($1); }
    | declaration declarations { $2->push_front($1); $$ = $2; };

declaration:
    method_declaration { $$ = $1; }
    | var_declaration { $$ = $1; };

method_declaration:
    "public" type "id"  "(" args ")" "{" statements_seq "}" { $$ = new MethodDeclaration(&driver, $2, $3, $5, $8); }
    | "public" type "id"  "(" ")" "{" statements_seq "}" { $$ = new MethodDeclaration(&driver, $2, $3, $7); };

var_declaration:
    type "id" ";" { $$ = new VarDeclaration(&driver, $1, $2); };

args:
    arg { $$ = new DeclarationList($1); }
    | arg "," args { $3->push_front($1); $$ = $3; };

arg:
    type "id" { $$ = new VarDeclaration(&driver, $1, $2); };

type:
    simple_type { $$ = $1; }
    | array_type {  $$ = $1; };

simple_type:
    "int" {  $$ = new IntType(); }
    | "boolean" { $$ = new BoolType(); }
    | "void" { $$ = new VoidType(); }
    | type_id { $$ = $1; };

array_type:
    simple_type "[" "]" { $$ = new ArrayType($1); };

type_id:
    "id" { $$ = new IdType(&driver, $1); };

statements_seq:
    %empty { $$ = new StatementList(); }
    | statement statements_seq { $2->push_front($1); $$ = $2; };

statement:
    "assert" "(" expression ")" ";" { $$ = new AssertStatement($3); }
    | var_declaration { $$ = $1; }
    | "{" statements_seq "}" { $$ = $2; }
    | "if" "(" expression ")" statement { $$ = new IfStatement($3, $5); }
    | "if" "(" expression ")" statement "else" statement { $$ = new IfStatement($3, $5, $7); }
    | "while" "(" expression ")" statement { $$ = new WhileStatement($3, $5); }
    | "print" "(" expression ")" ";" { $$ = new PrintStatement($3); }
    | assignment ";" { $$ = $1; }
    | "return" expression ";" { $$ = new ReturnStatement($2); }
    | method_invocation ";" { $$ = $1; };

method_invocation:
    "id" "." "id" "(" ")" { $$ = new MethodCall(&driver, $3, $1); }
    | "id" "." "id" "(" expression_seq ")" { $$ = new MethodCall(&driver, $3, $1, $5); }
    | "this" "." "id" "(" ")" { $$ = new MethodCall(&driver, $3, "this"); }
    | "this" "." "id" "(" expression_seq ")" { $$ = new MethodCall(&driver, $3, "this", $5); };

field_invocation:
    "this" "." "id" { $$ = new IdExpression(&driver, $3, true); }
    | "this" "." "id" "[" expression "]" { $$ = new ArrayIdExpression(&driver, $3, $5, true); };

expression_seq:
    expression { $$ = new ExpressionList($1); }
    | expression "," expression_seq { $3->push_front($1); $$ = $3; };

assignment:
    "id" "=" expression { $$ = new SimpleAssignment($1, $3); }
    | "id" "[" expression "]" "=" expression { $$ = new ArrayAssignment($1, $3, $6); }
    | "this" "." "id" "=" expression { $$ = new FieldAssignment($3, $5); }
    | "this" "." "id" "[" expression "]" "=" expression { $$ = new FieldArrayAssignment($3, $5, $8); };

expression:
    binary_expression { $$ = $1; }
    | "id" "[" expression "]" { $$ = new ArrayIdExpression(&driver, $1, $3, false); } // local array variable
    | "id" "." "length" { $$ = new LenExpression(&driver, $1); }
    | "new" simple_type "[" expression "]" { new ArrayNewExpression(&driver, $2, $4); } // это неявный declaration?
    | "new" type_id "(" ")" { new NewExpression(&driver, $2); }                         // тоже неявный declaration? - пока ок
    | "!" expression { $$ = new UnaryOpExpression('!', $2); }
    | "(" expression ")" { $$ = $2; }
    | "id" { $$ = new IdExpression(&driver, $1, false); } // local variable
    | "number" { $$ = new IntExpression($1); }
    | "true" { $$ = new BoolExpression(true); }
    | "false" { $$ = new BoolExpression(false); }
    | method_invocation { $$ = $1; }
    | field_invocation { $$ = $1; };

%left "&&" "||" "!";
%left "<" ">" "==";
%left "+" "-";
%left "*" "/" "%";

binary_expression:
    expression "&&" expression { $$ = new BinaryOpExpression('&', $1, $3); }
    | expression "||" expression { $$ = new BinaryOpExpression('|', $1, $3); }
    | expression "<" expression { $$ = new BinaryOpExpression('<', $1, $3); }
    | expression ">" expression { $$ = new BinaryOpExpression('>', $1, $3); }
    | expression "==" expression { $$ = new BinaryOpExpression('=', $1, $3); }
    | expression "+" expression { $$ = new BinaryOpExpression('+', $1, $3); }
    | expression "-" expression { $$ = new BinaryOpExpression('-', $1, $3); }
    | expression "*" expression { $$ = new BinaryOpExpression('*', $1, $3); }
    | expression "/" expression { $$ = new BinaryOpExpression('/', $1, $3); }
    | expression "%" expression { $$ = new BinaryOpExpression('%', $1, $3); };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}