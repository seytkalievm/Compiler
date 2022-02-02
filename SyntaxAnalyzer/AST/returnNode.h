#include <SyntaxAnalyzer/AST/elementNode.h>

class returnNode: elementNode {
public:
    elementNode Element;

    void SetElement(elementNode value) {
        Element = value;
    }
};