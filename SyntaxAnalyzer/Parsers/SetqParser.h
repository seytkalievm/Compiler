#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/SetqParser.h>
#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_SETQPARSER_H
#define COMPILER_SETQPARSER_H

setqNode SetqParser::Parse(Parser *parser, int *tokenNumber) {
    setqNode setq_node;
    setq_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    AtomParser atomParser;
    if (parser->GetToken(*tokenNumber).code != tokAtom) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    setq_node.SetAtom(atomParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    setq_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return setq_node;
}

#endif //COMPILER_SETQPARSER_H
