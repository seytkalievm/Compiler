#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/rootNode.h>

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

class Parser {
    std::vector<Token> tokenList;
public:
    rootNode ProgramParse(std::vector<Token> List);
    Token GetToken(int tokenNumber);
    void ErrorMessage(int line, int position);
};

#endif //COMPILER_PARSER_H