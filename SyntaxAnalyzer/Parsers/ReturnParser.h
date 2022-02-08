#include <SyntaxAnalyzer/AST/returnNode.h>

#ifndef COMPILER_RETURNPARSER_H
#define COMPILER_RETURNPARSER_H

class Parser;

class ReturnParser {
public:
    returnNode Parse(Parser parser, int *tokenNumber);
};

#endif //COMPILER_RETURNPARSER_H
