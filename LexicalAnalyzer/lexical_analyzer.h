#include <string>
#include <fstream>
#include <cstring>
#include <vector>

#include <Resources/tokens.h>

#ifndef COMPILER_LEXICAL_ANALYZER_H
#define COMPILER_LEXICAL_ANALYZER_H

class LexicalAnalyzer {
public:
    Token getNextToken(std::ifstream *file, int *curLine, int *curPos);
    std::vector<Token> Analyze(std::ifstream &sourcecode);
};

#endif