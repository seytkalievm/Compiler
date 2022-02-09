#include <SyntaxAnalyzer/Parsers/LiteralParser.h>
#include <SyntaxAnalyzer/Parser.h>

literalNode LiteralParser::Parse(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    literalNode literal_node;
    literal_node.SetToken(literalType);
    if (literalType.code == tokReal) {
        literal_node.SetType("Real");
        literal_node.SetReal(literalType.realVal);
    } else if (literalType.code == tokInt) {
        literal_node.SetType("Integer");
        literal_node.SetInteger(literalType.intVal);
    } else if (literalType.code == tokBoolean) {
        literal_node.SetType("Boolean");
        literal_node.SetBoolean(literalType.boolVal);
    }
    (*tokenNumber) ++;
    return literal_node;
}