#include "OperationOnListParser.h"
#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

operationListNode OperationOnListParser::Parse(Parser parser, int *tokenNumber) {
    operationListNode operation_list_node;
    Token curToken = parser.GetToken(*tokenNumber);
    operation_list_node.SetToken(curToken);
    (*tokenNumber) ++;

    ElementParser elementParser1;
    operation_list_node.SetElement1(elementParser1.Parse(parser, tokenNumber));

    if (curToken.code == tokCons) {
        ElementParser elementParser2;
        operation_list_node.SetElement2(elementParser2.Parse(parser, tokenNumber));
    }
    return operation_list_node;
}