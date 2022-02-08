#include "ArithmeticParser.h"
#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

arithmeticNode ArithmeticParser::Parse(Parser parser, int *tokenNumber) {
    arithmeticNode arithmetic_node;
    Token curToken = parser.GetToken(*tokenNumber);
    arithmetic_node.SetToken(curToken);
    (*tokenNumber) ++;

    ElementParser elementParser1;
    arithmetic_node.SetElement1(elementParser1.Parse(parser, tokenNumber));

    ElementParser elementParser2;
    arithmetic_node.SetElement2(elementParser2.Parse(parser, tokenNumber));
    return arithmetic_node;
}
