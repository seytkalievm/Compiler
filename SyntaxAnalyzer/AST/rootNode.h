#include <SyntaxAnalyzer/node.h>
#include <vector>

#ifndef COMPILER_ROOTNODE_H
#define COMPILER_ROOTNODE_H

class rootNode {
public:
    std::vector<Node> nodes;
    rootNode() {
        nodes = std::vector<Node>();
    }
    void AddNode(Node node){
        nodes.push_back(node);
    }
};

#endif