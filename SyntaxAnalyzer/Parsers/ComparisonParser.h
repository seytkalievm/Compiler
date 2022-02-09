#include <SyntaxAnalyzer/AST/comparisonNode.h>

#ifndef COMPILER_COMPARISONPARSER_H
#define COMPILER_COMPARISONPARSER_H

class Parser;

class ComparisonParser {
public:
    comparisonNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_COMPARISONPARSER_H
