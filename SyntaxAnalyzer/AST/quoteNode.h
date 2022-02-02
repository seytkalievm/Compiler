#include <SyntaxAnalyzer/AST/elementNode.h>

class quoteNode: elementNode {
public:
    elementNode Element;

    void SetElement(elementNode value) {
        Element = value;
    }
};