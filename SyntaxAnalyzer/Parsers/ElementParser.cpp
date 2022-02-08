#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>
#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parsers/LiteralParser.h>

elementNode ElementParser::Parse(Parser parser, int *tokenNumber) {
    Token elementType = parser.GetToken(*tokenNumber);
    if (elementType.code == tokOpenParenthesis) {

    } else if (elementType.code == tokAtom) {
        AtomParser atomParser;
        atomParser.Parse(parser, tokenNumber);
    } else if (elementType.code == tokBoolean || elementType.code == tokInt || elementType.code == tokReal) {
        LiteralParser literalParser;
        literalParser.Parse(parser, tokenNumber);
    } else {
        parser.ErrorMessage(elementType.line, elementType.position);
    }
}