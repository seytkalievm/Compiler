#include <SyntaxAnalyzer/AST/whileNode.h>

#ifndef COMPILER_WHILEPARSER_H
#define COMPILER_WHILEPARSER_H

class Parser;

class WhileParser {
public:
    whileNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_WHILEPARSER_H
