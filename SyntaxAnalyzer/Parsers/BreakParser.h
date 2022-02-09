#include <SyntaxAnalyzer/AST/breakNode.h>

#ifndef COMPILER_BREAKPARSER_H
#define COMPILER_BREAKPARSER_H

class Parser;

class BreakParser {
public:
    breakNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_BREAKPARSER_H
