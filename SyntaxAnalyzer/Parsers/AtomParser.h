#include <SyntaxAnalyzer/Parser.h>

#ifndef COMPILER_ATOMPARSER_H
#define COMPILER_ATOMPARSER_H

Node* AtomParser(Parser *parser, int *tokenNumber){
    Token atomType = parser->GetToken(*tokenNumber);
    NodeInvocation *atom_node = new NodeInvocation();
    (*tokenNumber) ++;
    atom_node->setName(atomType.value.atomVal);
    return atom_node;
}

#endif //COMPILER_ATOMPARSER_H
