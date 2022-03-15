#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ComparisonParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *comparison_node = new NodeInvocation();
    Token curToken = parser->GetToken(*tokenNumber);
    (*tokenNumber) ++;

    if (curToken.code == tokEqual) {
        comparison_node->setName("equal");
    }
    if (curToken.code == tokNonEqual) {
        comparison_node->setName("nonequal");
    }
    if (curToken.code == tokLess) {
        comparison_node->setName("less");
    }
    if (curToken.code == tokLessEq) {
        comparison_node->setName("lesseq");
    }
    if (curToken.code == tokGreater) {
        comparison_node->setName("greater");
    }
    if (curToken.code == tokGreaterEq) {
        comparison_node->setName("greatereq");
    }

    comparison_node->addParameter(ElementParser(parser, tokenNumber));
    comparison_node->addParameter(ElementParser(parser, tokenNumber));

    return comparison_node;
}
