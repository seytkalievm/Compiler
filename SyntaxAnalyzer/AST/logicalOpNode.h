#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class logicalOpNode: public elementNode {
public:
    elementNode Element1;
    elementNode Element2;
    void SetElement1(elementNode value) {
        Element1 = value;
    }
    void SetElement2(elementNode value) {
        Element2 = value;
    }
};