#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/AST/rootNode.h>
#include <SyntaxAnalyzer/Parser.h>

using namespace std;

#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H

int main() {
    ifstream sourcecode ("sourcecode.txt");
    vector<Token> tokenList = Analyze(sourcecode);
    Parser parser;
    parser.ProgramParse(tokenList);
    return 0;
}

#endif //COMPILER_MAIN_H