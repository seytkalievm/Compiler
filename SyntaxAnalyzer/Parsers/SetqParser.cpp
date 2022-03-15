#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* AtomParser(Parser *parser, int *tokenNumber);

Node* SetqParser(Parser *parser, int *tokenNumber) {
    NodeDeclaration *setq_node = new NodeDeclaration();
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokAtom) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    setq_node->setType("variable");
    setq_node->setName(AtomParser(parser, tokenNumber)->getName());

    setq_node->setExpression(ElementParser(parser, tokenNumber));
    return setq_node;
}
