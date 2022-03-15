#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LogicalOpParser(Parser *parser, int *tokenNumber) {
    Token curToken = parser->GetToken(*tokenNumber);
    NodeInvocation *logical_op_node = new NodeInvocation();
    
    if (curToken.code == tokAnd) {
        logical_op_node->setName("and");
    }
    if (curToken.code == tokOr) {
        logical_op_node->setName("or");
    }
    if (curToken.code == tokXor) {
        logical_op_node->setName("xor");
    }
    if (curToken.code == tokNot) {
        logical_op_node->setName("not");
    }

    (*tokenNumber) ++;
    logical_op_node->addParameter(ElementParser(parser, tokenNumber));

    if (curToken.code != tokNot) {
        logical_op_node->addParameter(ElementParser(parser, tokenNumber));
    }

    return logical_op_node;
}
