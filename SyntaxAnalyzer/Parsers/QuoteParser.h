#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/QuoteParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

#ifndef COMPILER_QUOTEPARSER_H
#define COMPILER_QUOTEPARSER_H

quoteNode QuoteParser::Parse(Parser *parser, int *tokenNumber) {
    quoteNode quote_node;
    quote_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser;
    quote_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return quote_node;
}

#endif //COMPILER_QUOTEPARSER_H
