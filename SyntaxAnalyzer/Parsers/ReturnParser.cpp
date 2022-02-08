#include <SyntaxAnalyzer/Parsers/ReturnParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parser.h>

returnNode ReturnParser::Parse(Parser parser, int *tokenNumber) {
    returnNode return_node;
    return_node.SetToken(parser.GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser;
    return_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return return_node;
}