#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class logicalOpNode: elementNode {
public:
    string op;
    elementNode Element1;
    elementNode Element2;
};