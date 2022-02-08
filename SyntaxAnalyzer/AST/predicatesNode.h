#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class predicatesNode: public elementNode {
public:
    elementNode Element;
    void SetElement(elementNode value) {
        Element = value;
    }
};