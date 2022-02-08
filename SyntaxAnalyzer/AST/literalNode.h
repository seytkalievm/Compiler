#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/listNode.h>
#include <string>

#ifndef COMPILER_LITERALNODE_H
#define COMPILER_LITERALNODE_H

class literalNode: public elementNode {
public:
    std::string type;
    int IntegerLiteral;
    bool BooleanLiteral;
    double RealLiteral;
    listNode ListLiteral;

    void SetType(std::string name) {
        type = name;
    }
    void SetInteger(int value) {
        IntegerLiteral = value;
    }
    void SetBoolean(bool value) {
        BooleanLiteral = value;
    }
    void SetReal(double value) {
        RealLiteral = value;
    }
    void SetList(listNode value) {
        ListLiteral = value;
    }
};

#endif