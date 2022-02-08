#include "BreakParser.h"
#include <SyntaxAnalyzer/Parser.h>

breakNode BreakParser::Parse(Parser parser, int *tokenNumber) {
    breakNode break_node;
    break_node.SetToken(parser.GetToken(*tokenNumber));
    (*tokenNumber) ++;
    return break_node;
}