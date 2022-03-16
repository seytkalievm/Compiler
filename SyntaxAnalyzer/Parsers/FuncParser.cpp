#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* AtomParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);
Node* ParameterParser(Parser *parser, int *tokenNumber);

Node* FuncParser(Parser *parser, int *tokenNumber) {
    NodeDeclaration *func_node = new NodeDeclaration();
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokAtom) {
        std::cerr << "here\n";
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }

    func_node->setType("functionNew");
    func_node->setName(AtomParser(parser, tokenNumber)->getName());

    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    (*tokenNumber) ++;

    while (parser->GetToken(*tokenNumber).code != tokCloseParenthesis) {
        func_node->addParameter(ParameterParser(parser, tokenNumber));
    }

    (*tokenNumber) ++;
    auto expression = ElementParser(parser, tokenNumber);
    func_node->setExpression(expression);
    return func_node;
}
