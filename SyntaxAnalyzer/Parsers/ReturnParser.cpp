#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ReturnParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *return_node = new NodeInvocation();
    return_node->setName("retrun");
    (*tokenNumber) ++;

    return_node->addParameter(ElementParser(parser, tokenNumber));
    return return_node;
}
