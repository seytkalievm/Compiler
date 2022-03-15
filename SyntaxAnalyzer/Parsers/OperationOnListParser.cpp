#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* OperationOnListParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *operation_list_node = new NodeInvocation();
    Token curToken = parser->GetToken(*tokenNumber);
    
    if (curToken.code == tokHead) {
        operation_list_node->setName("head");
    }
    if (curToken.code == tokTail) {
        operation_list_node->setName("tail");
    }
    if (curToken.code == tokCons) {
        operation_list_node->setName("cons");
    }

    (*tokenNumber) ++;

    operation_list_node->addParameter(ElementParser(parser, tokenNumber));

    if (curToken.code == tokCons) {
       operation_list_node->addParameter(ElementParser(parser, tokenNumber));
    }

    return operation_list_node;
}
