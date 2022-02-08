#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/atomNode.h>

class setqNode: public elementNode {
public:
    atomNode Atom;
    elementNode Element;

    void SetAtom(atomNode value){
        Atom = value;
    }
    void SetElement(elementNode value){
        Element = value;
    }
};