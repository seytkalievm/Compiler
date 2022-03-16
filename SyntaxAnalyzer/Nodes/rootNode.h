#include <vector>
#include <SyntaxAnalyzer/Nodes/node.h>
#include <SyntaxAnalyzer/Nodes/nodeDeclaration.h>
#include <SyntaxAnalyzer/Nodes/nodeInvocation.h>
#include <SyntaxAnalyzer/Nodes/nodeLiteral.h>
#include <SyntaxAnalyzer/Nodes/nodeParameter.h>

#ifndef COMPILER_ROOTNODE_H
#define COMPILER_ROOTNODE_H

class RootNode {
public:
    std::vector <Node*> nodes;
    RootNode() {}

    void AddChild(Node* node) {
        nodes.push_back(node);
    }
};

#endif //COMPILER_ROOTNODE_H
