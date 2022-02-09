#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/LogicalOpParser.h>

logicalOpNode LogicalOpParser::Parse(Parser *parser, int *tokenNumber) {
    Token curToken = parser->GetToken(*tokenNumber);
    logicalOpNode logical_op_node;
    logical_op_node.SetToken(curToken);
    (*tokenNumber) ++;
    ElementParser elementParser1;
    logical_op_node.SetElement1(elementParser1.Parse(parser, tokenNumber));
    if (curToken.code != tokNot) {
        ElementParser elementParser2;
        logical_op_node.SetElement2(elementParser2.Parse(parser, tokenNumber));
    }
    return logical_op_node;
}