#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_BREAKPARSER_H
#define COMPILER_BREAKPARSER_H

Node* BreakParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *break_node = new NodeInvocation();
    (*tokenNumber) ++;
    break_node->setName("break");
    return break_node;
}

#endif //COMPILER_BREAKPARSER_H
