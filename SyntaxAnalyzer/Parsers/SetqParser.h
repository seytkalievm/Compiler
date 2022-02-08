#include <SyntaxAnalyzer/AST/setqNode.h>

#ifndef COMPILER_SETQPARSER_H
#define COMPILER_SETQPARSER_H

class Parser;

class SetqParser {
public:
    setqNode Parse(Parser parser, int *tokenNumber);
};

#endif //COMPILER_SETQPARSER_H
