#include <SyntaxAnalyzer/AST/listNode.h>

#ifndef COMPILER_LITERALLISTPARSER_H
#define COMPILER_LITERALLISTPARSER_H

class Parser;

class LiteralListParser {
public:
    listNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_LITERALLISTPARSER_H
