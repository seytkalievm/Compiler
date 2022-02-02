#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>
#include <string>

class literalNode: elementNode {
public:
    string type;
    int IntegerLiteral;
    bool BooleanLiteral;
    double RealLiteral;
    listNode ListLiteral;

    void SetType(string name) {
        type = name;
    }
    void SetInteger(int value) {
        IntegerLiteral = value;
    }
    void SetBoolean(bool value) {
        BooleanLiteral = value;
    }
    void SetReal(double value) {
        FloatLiteral = value;
    }
    void SetList(listNode value) {
        ListLiteral = value;
    }
};