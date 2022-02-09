#include <SyntaxAnalyzer/Parsers/FuncParser.h>
#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralListParser.h>
#include <SyntaxAnalyzer/Parser.h>

funcNode FuncParser::Parse(Parser *parser, int *tokenNumber) {
    funcNode func_node;
    func_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokAtom) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).line, parser->GetToken(*tokenNumber).position);
    }
    AtomParser atomParser;
    func_node.SetAtom(atomParser.Parse(parser, tokenNumber));
    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).line, parser->GetToken(*tokenNumber).position);
    }
    LiteralListParser literalListParser;
    func_node.SetList(literalListParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    func_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return func_node;
}