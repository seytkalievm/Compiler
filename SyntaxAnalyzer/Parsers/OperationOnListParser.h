#include <SyntaxAnalyzer/AST/operationListNode.h>

#ifndef COMPILER_OPERATIONONLISTPARSER_H
#define COMPILER_OPERATIONONLISTPARSER_H

class Parser;

class OperationOnListParser {
public:
    operationListNode Parse(Parser parser, int *tokenNumber);
};

#endif //COMPILER_OPERATIONONLISTPARSER_H
