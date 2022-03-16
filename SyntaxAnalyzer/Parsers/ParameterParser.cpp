#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ParameterParser(Parser *parser, int *tokenNumber){
    Token currentToken = parser->GetToken(*tokenNumber);
    NodeParameter *parameter_node = new NodeParameter();
    (*tokenNumber) ++;
    parameter_node->setName(currentToken.value.atomVal);
    return parameter_node;
}
