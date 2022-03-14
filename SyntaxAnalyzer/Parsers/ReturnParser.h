#include <SyntaxAnalyzer/Parsers/ReturnParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_RETURNPARSER_H
#define COMPILER_RETURNPARSER_H

returnNode ReturnParser::Parse(Parser *parser, int *tokenNumber) {
    returnNode return_node;
    return_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser;
    return_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return return_node;
}

#endif //COMPILER_RETURNPARSER_H
