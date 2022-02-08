#include <SyntaxAnalyzer/AST/elementNode.h>

class quoteNode: public elementNode {
public:
    elementNode Element;

    void SetElement(elementNode value) {
        Element = value;
    }
};