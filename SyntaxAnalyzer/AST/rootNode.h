#include <SyntaxAnalyzer/node.h>
#include <vector>

class rootNode {
    std::vector<Node> nodes;
    rootNode() {
        nodes = std::vector<Node>();
    }
    void AddNode(Node node){
        nodes.push_back(node);
    }
};