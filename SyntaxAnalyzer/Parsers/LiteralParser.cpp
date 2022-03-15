#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* LiteralParser(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    NodeLiteral *literal_node = new NodeLiteral();
    if (literalType.code == tokInt) {
        literal_node->setName("int");
        literal_node->setIntVal(literalType.value.intVal);
    }
    if (literalType.code == tokReal) {
        literal_node->setName("real");
        literal_node->setIntVal(literalType.value.realVal);
    }
    if (literalType.code == tokBoolean) {
        literal_node->setName("boolean");
        literal_node->setIntVal(literalType.value.boolVal);
    }
    (*tokenNumber) ++;
    return literal_node;
}
