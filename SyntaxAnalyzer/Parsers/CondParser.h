#include <SyntaxAnalyzer/AST/condNode.h>

#ifndef COMPILER_CONDPARSER_H
#define COMPILER_CONDPARSER_H

class Parser;

class CondParser {
public:
    condNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_CONDPARSER_H
