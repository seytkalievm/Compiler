#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* BreakParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *break_node = new NodeInvocation();
    (*tokenNumber) ++;
    break_node->setName("break");
    return break_node;
}
