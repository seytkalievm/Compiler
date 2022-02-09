#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class evaluatorNode: public elementNode {
public:
    elementNode Element;
    void SetElement(elementNode value) {
        Element = value;
    }
};