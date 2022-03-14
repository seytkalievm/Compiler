#include <SyntaxAnalyzer/Parsers/LiteralParser.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_LITERALPARSER_H
#define COMPILER_LITERALPARSER_H

literalNode LiteralParser::Parse(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    literalNode literal_node;
    literal_node.SetToken(literalType);
    (*tokenNumber) ++;
    return literal_node;
}

#endif //COMPILER_LITERALPARSER_H
