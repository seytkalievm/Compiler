#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* EvalParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *evaluator_node = new NodeInvocation();
    (*tokenNumber) ++;
    evaluator_node->setName("eval");
    evaluator_node->addParameter(ElementParser(parser, tokenNumber));
    return evaluator_node;
}
