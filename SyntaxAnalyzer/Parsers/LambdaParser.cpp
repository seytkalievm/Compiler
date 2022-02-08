#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/LambdaParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

lambdaNode LambdaParser::Parse(Parser parser, int *tokenNumber) {
    lambdaNode lambda_node;
    lambda_node.SetToken(parser.GetToken(*tokenNumber));
    (*tokenNumber) ++;
    if (parser.GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser.ErrorMessage(parser.GetToken(*tokenNumber).line, parser.GetToken(*tokenNumber).position);
    }
    ListParser listParser;
    lambda_node.SetList(listParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    lambda_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return lambda_node;
}