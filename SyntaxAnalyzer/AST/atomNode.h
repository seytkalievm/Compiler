#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/literalNode.h>
#include <string>

#ifndef COMPILER_ATOM_H
#define COMPILER_ATOM_H

class atomNode: public elementNode {
public:
    std::string name;
    literalNode literal;

    void SetName(std::string name) {
        this->name = name;
    }
    void SetLiteral(literalNode x) {
        literal = x;
    }
};

#endif