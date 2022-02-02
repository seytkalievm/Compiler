#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class arithmeticNode: elementNode {
public:
    string op;
    elementNode Element1;
    elementNode Element2;
};