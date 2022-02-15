#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/literalNode.h>
#include <string>

#ifndef COMPILER_ATOM_H
#define COMPILER_ATOM_H

class atomNode: public elementNode {
public:
    void SetValue(elementNode x) {
        AddChild(x);
    }
};

#endif