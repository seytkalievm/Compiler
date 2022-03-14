#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/LambdaParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralListParser.h>

#ifndef COMPILER_LAMBDAPARSER_H
#define COMPILER_LAMBDAPARSER_H

lambdaNode LambdaParser::Parse(Parser *parser, int *tokenNumber) {
    lambdaNode lambda_node;
    lambda_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    LiteralListParser literalListParser;
    lambda_node.SetList(literalListParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    lambda_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return lambda_node;
}

#endif //COMPILER_LAMBDAPARSER_H
