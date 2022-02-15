#include <SyntaxAnalyzer/Parsers/AtomParser.h>
#include <SyntaxAnalyzer/Parser.h>

atomNode AtomParser::Parse(Parser *parser, int *tokenNumber){
    Token atomType = parser->GetToken(*tokenNumber);
    atomNode atom_node;
    (*tokenNumber) ++;
    atom_node.SetToken(atomType);
    return atom_node;
}