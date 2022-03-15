#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* WhileParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *while_node = new NodeInvocation();
    while_node->setName("while");
    (*tokenNumber) ++;
    while_node->addParameter(ElementParser(parser, tokenNumber));
    while_node->addParameter(ElementParser(parser, tokenNumber));
    return while_node;
}
