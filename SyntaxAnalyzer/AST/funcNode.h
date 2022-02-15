#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/atomNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>

class funcNode: public elementNode {
public:
    void SetAtom(atomNode value) {
        AddChild(value);
    }
    void SetList(listNode value) {
        AddChild(value);
    }
    void SetElement(elementNode value) {
        AddChild(value);
    }
};