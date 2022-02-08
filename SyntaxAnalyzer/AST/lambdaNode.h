#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>

class lambdaNode: public elementNode {
public:
    listNode List;
    elementNode Element;

    void SetList(listNode value) {
        List = value;
    }
    void SetElement(elementNode value) {
        Element = value;
    }
};