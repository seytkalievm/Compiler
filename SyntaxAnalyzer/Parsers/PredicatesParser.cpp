#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* PredicatesParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *predicates_node = new NodeInvocation();
    Token curToken = parser->GetToken(*tokenNumber);
    
    if (curToken.code == tokIsInt) {
        predicates_node->setName("isint");
    }
    if (curToken.code == tokIsReal) {
        predicates_node->setName("isreal");
    }
    if (curToken.code == tokIsBool) {
        predicates_node->setName("isbool");
    }
    if (curToken.code == tokIsNull) {
        predicates_node->setName("isnull");
    }
    if (curToken.code == tokIsAtom) {
        predicates_node->setName("isatom");
    }
    if (curToken.code == tokIsList) {
        predicates_node->setName("islist");
    }

    (*tokenNumber) ++;
    predicates_node->addParameter(ElementParser(parser, tokenNumber));
    return predicates_node;
}
