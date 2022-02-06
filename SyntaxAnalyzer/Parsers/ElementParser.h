#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Resources/tokens.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_ELEMENTPARSER_H
#define COMPILER_ELEMENTPARSER_H

elementNode ParseElement(Parser parser, int *tokenNumber) {
    if (parser.GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser.ErrorMessage(parser.GetToken(*tokenNumber).line, parser.GetToken(*tokenNumber).position);
    }
    (*tokenNumber) ++;
    Token elementName = parser.GetToken(*tokenNumber);
    if (elementName.code == tokQuote) {

    }
}

#endif