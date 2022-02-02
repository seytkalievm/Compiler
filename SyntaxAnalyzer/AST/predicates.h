#include <SyntaxAnalyzer/AST/elementNode.h>
#include <string>

class predicatesNode: elementNode {
public:
    string op;
    elementNode Element;
};