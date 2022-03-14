#include <SyntaxAnalyzer/Parsers/WhileParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_WHILEPARSER_H
#define COMPILER_WHILEPARSER_H

whileNode WhileParser::Parse(Parser *parser, int *tokenNumber) {
    whileNode while_node;
    while_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser1;
    while_node.SetElement1(elementParser1.Parse(parser, tokenNumber));
    ElementParser elementParser2;
    while_node.SetElement2(elementParser2.Parse(parser, tokenNumber));
    return while_node;
}

#endif //COMPILER_WHILEPARSER_H
