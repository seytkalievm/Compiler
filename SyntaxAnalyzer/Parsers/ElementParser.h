#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Resources/tokens.h>
#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/AST/elementNode.h>

#ifndef COMPILER_ELEMENTPARSER_H
#define COMPILER_ELEMENTPARSER_H

Node* ElementParser(Parser *parser, int *tokenNumber) {
    Token elementType = parser->GetToken(*tokenNumber);
    if (elementType.code == tokOpenParenthesis) {
        ListParser listParser;
        elementNode el = listParser.Parse(parser, tokenNumber);
        return el;
    } else if (elementType.code == tokAtom) {
        AtomParser atomParser;
        return atomParser.Parse(parser, tokenNumber);
    } else if (elementType.code == tokBoolean || elementType.code == tokInt || elementType.code == tokReal) {
        LiteralParser literalParser;
        return literalParser.Parse(parser, tokenNumber);
    } else {
        parser->ErrorMessage(elementType.location.line, elementType.location.position);
    }
}

#endif