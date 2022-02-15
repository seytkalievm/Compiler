#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>
#include <vector>

#ifndef COMPILER_LISTNODE_H
#define COMPILER_LISTNODE_H

class listNode: public elementNode {
public:
    void AddElement(elementNode element) {
        AddChild(element);
    }
};

#endif