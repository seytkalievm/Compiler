#include <SyntaxAnalyzer/Parsers/CondParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parser.h>

condNode CondParser::Parse(Parser parser, int *tokenNumber) {
    condNode cond_node;
    (*tokenNumber) ++;
    ElementParser elementParser1;
    cond_node.SetElement1(elementParser1.Parse(parser, tokenNumber));
    ElementParser elementParser2;
    cond_node.SetElement2(elementParser2.Parse(parser, tokenNumber));

    if (parser.GetToken(*tokenNumber).code != tokOpenBracket) {
        parser.ErrorMessage(parser.GetToken(*tokenNumber).line, parser.GetToken(*tokenNumber).position);
    }
    (*tokenNumber) ++;

    ElementParser elementParser3;
    cond_node.SetElement3(elementParser3.Parse(parser, tokenNumber));

    if (parser.GetToken(*tokenNumber).code != tokCloseBracket) {
        parser.ErrorMessage(parser.GetToken(*tokenNumber).line, parser.GetToken(*tokenNumber).position);
    }
    (*tokenNumber) ++;
    return cond_node;
}