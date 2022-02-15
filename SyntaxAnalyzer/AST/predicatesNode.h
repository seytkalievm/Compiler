#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class predicatesNode: public elementNode {
public:
    void SetElement(elementNode value) {
        AddChild(value);
    }
};