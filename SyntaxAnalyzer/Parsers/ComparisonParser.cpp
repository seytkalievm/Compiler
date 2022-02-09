#include "ComparisonParser.h"
#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

comparisonNode ComparisonParser::Parse(Parser *parser, int *tokenNumber) {
    comparisonNode comparison_node;
    Token curToken = parser->GetToken(*tokenNumber);
    comparison_node.SetToken(curToken);
    (*tokenNumber) ++;

    ElementParser elementParser1;
    comparison_node.SetElement1(elementParser1.Parse(parser, tokenNumber));

    ElementParser elementParser2;
    comparison_node.SetElement2(elementParser2.Parse(parser, tokenNumber));

    return comparison_node;
}