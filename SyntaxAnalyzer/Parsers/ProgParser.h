#include <SyntaxAnalyzer/AST/progNode.h>

#ifndef COMPILER_PROGPARSER_H
#define COMPILER_PROGPARSER_H

class Parser;

class ProgParser {
public:
    progNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_PROGPARSER_H
