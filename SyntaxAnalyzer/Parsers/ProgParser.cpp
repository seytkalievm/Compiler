#include <SyntaxAnalyzer/Parsers/ProgParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralListParser.h>
#include <SyntaxAnalyzer/Parser.h>

progNode ProgParser::Parse(Parser *parser, int *tokenNumber) {
    progNode prog_node;
    prog_node.SetToken(parser->GetToken(*tokenNumber));
    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).line, parser->GetToken(*tokenNumber).position);
    }
    LiteralListParser literalListParser;
    prog_node.SetList(literalListParser.Parse(parser, tokenNumber));
    ElementParser elementParser;
    prog_node.SetElement(elementParser.Parse(parser, tokenNumber));
    return prog_node;
}