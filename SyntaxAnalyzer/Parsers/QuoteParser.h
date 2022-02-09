#include <SyntaxAnalyzer/AST/quoteNode.h>

#ifndef COMPILER_QUOTEPARSER_H
#define COMPILER_QUOTEPARSER_H

class Parser;

class QuoteParser {
public:
    quoteNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_QUOTEPARSER_H
