#include <SyntaxAnalyzer/AST/elementNode.h>
#include <SyntaxAnalyzer/AST/literalNode.h>
#include <string>

class atomNode: elementNode {
public:
    string name;
    literalNode literal;

    void SetName(string name) {
        this.name = name;
    }
    void SetLiteral(literalNode x) {
        literal = x;
    }
};