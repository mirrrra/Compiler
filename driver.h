#pragma once

#include <map>
#include <fstream>
#include <string>
#include "scanner.h"
#include "parser.hh"
#include "program.h"

class Driver {
public:
    Driver();
    // std::map<std::string, std::string> variables;
    int result;
    int parse(const std::string& f);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;
    bool location_debug;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    Program* program;
private:
    std::ifstream stream;

};