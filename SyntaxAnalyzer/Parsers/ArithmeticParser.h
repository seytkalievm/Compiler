#include <SyntaxAnalyzer/AST/arithmeticNode.h>

#ifndef COMPILER_ARITHMETICPARSER_H
#define COMPILER_ARITHMETICPARSER_H

class Parser;

class ArithmeticParser {
public:
    arithmeticNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_ARITHMETICPARSER_H
