#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* AtomParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);

Node* FuncParser(Parser *parser, int *tokenNumber) {
    NodeDeclaration *func_node = new NodeDeclaration();
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokAtom) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }

    func_node->setType("function");
    func_node->setName(AtomParser(parser, tokenNumber)->getName());

    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    (*tokenNumber) ++;

    auto parameters = LiteralListParser(parser, tokenNumber);
    for (auto parameter: parameters->getParameters()) {
        func_node->addParameter(parameter);
    }

    (*tokenNumber) ++;
    auto expression = ElementParser(parser, tokenNumber);
    func_node->setExpression(expression);
    return func_node;
}
