#include <SyntaxAnalyzer/AST/elementNode.h>

class condNode: elementNode {
public:
    elementNode Element1;
    elementNode Element2;
    elementNode Element3;

    void SetElement1(elementNode value) {
        Element1 = value;
    }
    void SetElement2(elementNode value) {
        Element2 = value;
    }
    void SetElement3(elementNode value) {
        Element3 = value;
    }
};