#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* AtomParser(Parser *parser, int *tokenNumber){
    Token atomType = parser->GetToken(*tokenNumber);
    NodeInvocation *atom_node = new NodeInvocation();
    (*tokenNumber) ++;
    atom_node->setName(atomType.value.atomVal);
    return atom_node;
}
