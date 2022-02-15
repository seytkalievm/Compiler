#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>

class lambdaNode: public elementNode {
public:
    void SetList(listNode value) {
        AddChild(value);
    }
    void SetElement(elementNode value) {
        AddChild(value);
    }
};