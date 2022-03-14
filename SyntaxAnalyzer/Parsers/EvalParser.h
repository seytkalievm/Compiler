#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/EvalParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

#ifndef COMPILER_EVALPARSER_H
#define COMPILER_EVALPARSER_H

evaluatorNode EvalParser::Parse(Parser *parser, int *tokenNumber) {
    evaluatorNode evaluator_node;
    evaluator_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    ElementParser elementParser;
    evaluator_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return evaluator_node;
}

#endif //COMPILER_EVALPARSER_H
