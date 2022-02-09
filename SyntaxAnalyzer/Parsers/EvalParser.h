#include <SyntaxAnalyzer/AST/evaluatorNode.h>

#ifndef COMPILER_EVALPARSER_H
#define COMPILER_EVALPARSER_H

class Parser;

class EvalParser {
public:
    evaluatorNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_EVALPARSER_H
