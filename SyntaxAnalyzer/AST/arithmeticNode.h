#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class arithmeticNode: public elementNode {
public:
    void SetElement1(elementNode value) {
        AddChild(value);
    }
    void SetElement2(elementNode value) {
        AddChild(value);
    }
};