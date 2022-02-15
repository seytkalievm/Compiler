#include <SyntaxAnalyzer/AST/elementNode.h>

class returnNode: public elementNode {
public:
    void SetElement(elementNode value) {
        AddChild(value);
    }
};