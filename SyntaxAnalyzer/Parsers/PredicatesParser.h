#include <SyntaxAnalyzer/Parsers/PredicatesParser.h>
#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

#ifndef COMPILER_PREDICATESPARSER_H
#define COMPILER_PREDICATESPARSER_H

predicatesNode PredicatesParser::Parse(Parser *parser, int *tokenNumber) {
    predicatesNode predicates_node;
    predicates_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser;
    predicates_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return predicates_node;
}

#endif //COMPILER_PREDICATESPARSER_H
