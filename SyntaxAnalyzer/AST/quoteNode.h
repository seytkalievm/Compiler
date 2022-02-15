#include <SyntaxAnalyzer/AST/elementNode.h>

class quoteNode: public elementNode {
public:
    void SetElement(elementNode value) {
        AddChild(value);
    }
};