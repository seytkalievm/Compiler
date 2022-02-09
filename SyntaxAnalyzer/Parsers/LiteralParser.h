#include <SyntaxAnalyzer/AST/literalNode.h>

#ifndef COMPILER_LITERALPARSER_H
#define COMPILER_LITERALPARSER_H

class Parser;

class LiteralParser {
public:
    literalNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_LITERALPARSER_H
