#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>
#include <vector>

#ifndef COMPILER_LISTNODE_H
#define COMPILER_LISTNODE_H

class listNode: public elementNode {
public:
    std::vector <elementNode> Elements;
    listNode() {
        Elements = std::vector <elementNode>();
    }
    void AddElement(elementNode element) {
        Elements.push_back(element);
    }
};

#endif