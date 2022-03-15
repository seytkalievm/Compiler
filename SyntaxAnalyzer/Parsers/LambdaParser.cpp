#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);

Node* LambdaParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *lambda_node = new NodeInvocation();
    lambda_node->setName("lambda");
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }

    lambda_node->addParameter(LiteralListParser(parser, tokenNumber));
    (*tokenNumber) ++;

    lambda_node->addParameter(ElementParser(parser, tokenNumber));

    return lambda_node;
}
