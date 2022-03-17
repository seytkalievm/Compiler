#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ParameterParser(Parser *parser, int *tokenNumber){
    Token currentToken = parser->GetToken(*tokenNumber);
    NodeParameter *parameter_node = new NodeParameter();
    (*tokenNumber) ++;
    parameter_node->setName(currentToken.value.atomVal);
    NodeDeclaration *nw = new NodeDeclaration();
    nw->setName(currentToken.value.atomVal); 
    nw->setType("variable");
    parameter_node->setDeclaration(nw);
    return parameter_node;
}
