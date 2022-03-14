#include <string>
#include <vector>

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

class Node {
public:
    std::string nodeType;

    virtual std::string getName();
    virtual std::vector<Node*> getParameters();
    virtual Node* getDeclaration();
    virtual Node* getExpression();

    virtual void setDeclaration();
    virtual void setExpression();
};

#endif //COMPILER_NODE_H
