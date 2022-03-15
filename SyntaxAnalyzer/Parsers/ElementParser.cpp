#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Resources/tokens.h>
#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* LiteralParser(Parser *parser, int *tokenNumber);
Node* AtomParser(Parser *parser, int *tokenNumber);
Node* ListParser(Parser *parser, int *tokenNumber);

Node* ElementParser(Parser *parser, int *tokenNumber) {
    Token elementType = parser->GetToken(*tokenNumber);
    if (elementType.code == tokOpenParenthesis) {
        return ListParser(parser, tokenNumber);
    } else if (elementType.code == tokAtom) {
        return AtomParser(parser, tokenNumber);
    } else if (elementType.code == tokBoolean || elementType.code == tokInt || elementType.code == tokReal) {
        return LiteralParser(parser, tokenNumber);
    } else {
        parser->ErrorMessage(elementType.location.line, elementType.location.position);
    }
}