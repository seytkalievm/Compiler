#include <string>
#include <vector>
#include "node.h"

#ifndef COMPILER_NODEParameter_H
#define COMPILER_NODEParameter_H

class NodeParameter: public Node {
public:
    std::string name;
    Node* declaration;

    NodeParameter() {
        this->nodeType = "Parameter";
    }

    virtual std::string getName() {
        return name;
    }
    virtual Node* getDeclaration() {
        return declaration;
    }

    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void setDeclaration(Node* x) {
        declaration = x;
    }
    
    virtual llvm::Value* codegen() {
        if (getDeclaration()->getType() == "variable") {
            llvm::Value *V = getDeclaration()->getExpression()->codegen();
            return V;
        }
        std::cout << "Something go wrong\n";
        exit(0);
    }
};

#endif 