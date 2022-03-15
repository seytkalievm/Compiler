#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LiteralListParser(Parser *parser, int *tokenNumber) {
    NodeLiteral *list_node = new NodeLiteral();
    list_node->setName("list");
    while (parser->GetToken(*tokenNumber).code != tokCloseParenthesis) {
        list_node->addListVal(ElementParser(parser, tokenNumber));
    }
    return list_node;
}
