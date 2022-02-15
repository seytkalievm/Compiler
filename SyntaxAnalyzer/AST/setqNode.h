#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/atomNode.h>

class setqNode: public elementNode {
public:
    void SetAtom(atomNode value){
        AddChild(value);
    }
    void SetElement(elementNode value){
        AddChild(value);
    }
};