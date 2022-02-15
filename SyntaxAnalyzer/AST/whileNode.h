#include <SyntaxAnalyzer/AST/elementNode.h>

class whileNode: public elementNode {
public:
    void SetElement1(elementNode value) {
        AddChild(value);
    }
    void SetElement2(elementNode value) {
        AddChild(value);
    }
};