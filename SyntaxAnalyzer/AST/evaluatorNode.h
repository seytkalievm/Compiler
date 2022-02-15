#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class evaluatorNode: public elementNode {
public:
    void SetElement(elementNode value) {
        AddChild(value);
    }
};