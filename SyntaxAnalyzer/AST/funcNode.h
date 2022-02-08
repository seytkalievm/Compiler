#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/atomNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>

class funcNode: public elementNode {
public:
    atomNode Atom;
    listNode List;
    elementNode Element;

    void SetAtom(atomNode value) {
        Atom = value;
    }
    void SetList(listNode value) {
        List = value;
    }
    void SetElement(elementNode value) {
        Element = value;
    }
};