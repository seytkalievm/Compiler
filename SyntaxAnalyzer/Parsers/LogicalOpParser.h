#include <SyntaxAnalyzer/AST/logicalOpNode.h>

#ifndef COMPILER_LOGICALOPPARSER_H
#define COMPILER_LOGICALOPPARSER_H

class Parser;

class LogicalOpParser {
public:
    logicalOpNode Parse(Parser *parser, int *tokenNumber);
};

#endif //COMPILER_LOGICALOPPARSER_H
