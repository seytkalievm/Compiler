#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Resources/tokens.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/elementNode.h>

#ifndef COMPILER_ELEMENTPARSER_H
#define COMPILER_ELEMENTPARSER_H

class Parser;

class ElementParser {
public:
    elementNode Parse(Parser parser, int *tokenNumber);
};

#endif