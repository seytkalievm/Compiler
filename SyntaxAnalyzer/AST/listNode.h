#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>
#include <vector>

class listNode: elementNode {
public:
    std::vector <elementNode> Elements;
    void AddElement(elementNode element) {
        Elements.push_back(element);
    }
};