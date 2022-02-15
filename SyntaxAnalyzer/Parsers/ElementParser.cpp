#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralParser.h>
#include <SyntaxAnalyzer/Parsers/ListParser.h>

elementNode ElementParser::Parse(Parser *parser, int *tokenNumber) {
    Token elementType = parser->GetToken(*tokenNumber);
    if (elementType.code == tokOpenParenthesis) {
        ListParser listParser;
        return listParser.Parse(parser, tokenNumber);
    } else if (elementType.code == tokAtom) {
        AtomParser atomParser;
        return atomParser.Parse(parser, tokenNumber);
    } else if (elementType.code == tokBoolean || elementType.code == tokInt || elementType.code == tokReal) {
        LiteralParser literalParser;
        return literalParser.Parse(parser, tokenNumber);
    } else {
        parser->ErrorMessage(elementType.location.line, elementType.location.position);
    }
}