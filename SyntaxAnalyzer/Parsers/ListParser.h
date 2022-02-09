#include <SyntaxAnalyzer/AST/listNode.h>

#ifndef COMPILER_LISTPARSER_H
#define COMPILER_LISTPARSER_H

class Parser;

class ListParser {
public:
    listNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_LISTPARSER_H
