#include <SyntaxAnalyzer/AST/lambdaNode.h>

#ifndef COMPILER_LAMBDAPARSER_H
#define COMPILER_LAMBDAPARSER_H

class Parser;

class LambdaParser {
public:
    lambdaNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_LAMBDAPARSER_H
