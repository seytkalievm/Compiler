#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/SetqParser.h>
#include <SyntaxAnalyzer/Parser.h>

setqNode SetqParser::Parse(Parser parser, int *tokenNumber) {
    setqNode setq_node;
    setq_node.SetToken(parser.GetToken(*tokenNumber));
    (*tokenNumber) ++;
    AtomParser atomParser;
    if (parser.GetToken(*tokenNumber).code != tokAtom) {
        parser.ErrorMessage(parser.GetToken(*tokenNumber).line, parser.GetToken(*tokenNumber).position);
    }
    setq_node.SetAtom(atomParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    setq_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return setq_node;
}