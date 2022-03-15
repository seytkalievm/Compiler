#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* QuoteParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *quote_node = new NodeInvocation();
    quote_node->setName("quote");
    (*tokenNumber) ++;

    quote_node->addParameter(ElementParser(parser, tokenNumber));
    return quote_node;
}
