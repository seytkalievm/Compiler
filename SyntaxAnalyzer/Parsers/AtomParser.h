#include <SyntaxAnalyzer/AST/atomNode.h>

#ifndef COMPILER_ATOMPARSER_H
#define COMPILER_ATOMPARSER_H

class Parser;

class AtomParser {
public:
    atomNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_ATOMPARSER_H
