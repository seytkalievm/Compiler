#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);

Node* ProgParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *prog_node = new NodeInvocation();
    prog_node->setName("prog");
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }

    prog_node->addParameter(LiteralListParser(parser, tokenNumber));
    (*tokenNumber) ++;

    prog_node->addParameter(ElementParser(parser, tokenNumber));

    return prog_node;
}
