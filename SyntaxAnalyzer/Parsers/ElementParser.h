#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Resources/tokens.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/Parser.h>

elementNode ParseElement(Parser parser, int *tokenNumber) {
    if (!parser.GetToken(tokenNumber) != tokOpenParenthesis) {

    }
}