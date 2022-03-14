#include <string>
#include <vector>
#include "node.h"

#ifndef COMPILER_NODEDECLARATION_H
#define COMPILER_NODEDECLARATION_H

class NodeDeclaration: public Node {
public:
    std::string name;
    std::vector <Node*> parameters;
    Node* expression;

    NodeDeclaration() {
        this->nodeType = "Declaration";
    }

    virtual std::string getName() {
        return name;
    }
    virtual std::vector <Node*> getParameters() {
        return parameters;
    }
    virtual Node* getExpression() {
        return expression;
    }

    virtual void setExpression(Node* expression) {
        this->expression = expression;
        this->nodeType = "Declaration";
    }
    void setName(std::string name) {
        this->name = name;
    }
    void addParameter(Node* node) {
        parameters.push_back(node);
    }
};

#endif //COMPILER_NODEDECLARATION_H
