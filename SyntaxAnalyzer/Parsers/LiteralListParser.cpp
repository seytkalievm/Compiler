#include "LiteralListParser.h"
#include "ElementParser.h"
#include <SyntaxAnalyzer/Parser.h>

listNode LiteralListParser::Parse(Parser *parser, int *tokenNumber) {
    listNode list_node;
    Token listToken;
    listToken.code = tokList;
    list_node.SetToken(listToken);
    while (parser->GetToken(*tokenNumber).code != tokCloseParenthesis) {
        ElementParser elementParser;
        list_node.AddElement(elementParser.Parse(parser, tokenNumber));
    }
    return list_node;
}