#include "Resources/tokens.h"
#include <vector>
#include <iostream>

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

class Node {
public:
    Token token;
    std::vector <Node> children;

    Node() {
        children = std::vector<Node>();
    }

    void SetToken(Token token) {
        this->token = token;
    }
    void AddChild(Node node) {
        children.push_back(node);
    }
};

#endif //COMPILER_TOKENS_H