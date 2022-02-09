#include <SyntaxAnalyzer/AST/predicatesNode.h>

#ifndef COMPILER_PREDICATESPARSER_H
#define COMPILER_PREDICATESPARSER_H

class Parser;

class PredicatesParser {
public:
    predicatesNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_PREDICATESPARSER_H
