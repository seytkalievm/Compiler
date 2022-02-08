#include <SyntaxAnalyzer/AST/elementNode.h>

class returnNode: public elementNode {
public:
    elementNode Element;

    void SetElement(elementNode value) {
        Element = value;
    }
};