cmake_minimum_required(VERSION 3.9)
project(Compiler)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(
        HEADERS
        ${Compiler_SOURCE_DIR}/driver.h
        ${Compiler_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${Compiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${Compiler_SOURCE_DIR}/parser.hh
        COMPILE_FLAGS "-Wcounterexamples"
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${Compiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compiler_SOURCE_DIR}/build)
set(
        EXPR_SOURCES
        Expressions/BoolExpression.cpp
        Expressions/ExpressionList.cpp
        Expressions/IdExpression.cpp
        Expressions/IntExpression.cpp
        Expressions/LenExpression.cpp
        Expressions/MethodCall.cpp
        Expressions/NewExpression.cpp
        Expressions/OpExpression.cpp
)

set(
        STMT_SOURCES
        Statements/ArrayAssignment.cpp
        Statements/AssertStatement.cpp
        Statements/FieldAssignment.cpp
        Statements/IfStatement.cpp
        Statements/PrintStatement.cpp
        Statements/ReturnStatement.cpp
        Statements/SimpleAssignment.cpp
        Statements/StatementList.cpp
        Statements/WhileStatement.cpp
)

set(
        DECL_SOURCES
        Declarations/ClassDeclaration.cpp
        Declarations/ClassDeclarationList.cpp
        Declarations/DeclarationList.cpp
        Declarations/MainClassDeclaration.cpp
        Declarations/MethodDeclaration.cpp
        Declarations/VarDeclaration.cpp
        Declarations/ArrayType.cpp
        Declarations/IdType.cpp
        Declarations/BoolType.cpp
        Declarations/IntType.cpp
        Declarations/VoidType.cpp
)

set(
        VISITOR_SOURCES
        Visitors/InterpreterVisitor.cpp
        Visitors/PrintVisitor.cpp
        Visitors/SymbolTreeVisitor.cpp
)

set(
        EXTRA_SOURCES
        Sources/Optional.cpp
        Sources/Table.cpp
        Sources/Symbol.cpp
)

set(
        BASE_SOURCES
        BaseElement/ArrayObject.cpp
        BaseElement/BoolObject.cpp
        BaseElement/ClassObject.cpp
        BaseElement/FunctionObject.cpp
        BaseElement/IntObject.cpp
        BaseElement/Object.cpp
        BaseElement/UninitObject.cpp
)

add_executable(
        Compiler
        main.cpp
        driver.cpp
        ${EXPR_SOURCES}
        ${STMT_SOURCES}
        ${DECL_SOURCES}
        ${VISITOR_SOURCES}
        ${EXTRA_SOURCES}
        ${BASE_SOURCES}
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        program.cpp

)

target_include_directories(Compiler PRIVATE ${Compiler_SOURCE_DIR})
