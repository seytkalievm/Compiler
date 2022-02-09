#include <SyntaxAnalyzer/AST/funcNode.h>

#ifndef COMPILER_FUNCPARSER_H
#define COMPILER_FUNCPARSER_H

class Parser;

class FuncParser {
public:
    funcNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_FUNCPARSER_H
