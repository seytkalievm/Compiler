#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/rootNode.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

class Parser {
    std::vector<Token> tokenList;
    rootNode ProgramParse(std::vector<Token> List) {
        tokenList = List;
        rootNode root = rootNode();
        int tokenNumber = 0;
        while (1) {
            ParseElement(this, &tokenNumber);
        }
        return rootNode;
    }
    Token GetToken(int tokenNumber) {
        if (tokenNumber >= tokenList.size()) {
            return nullptr;
        }
        return tokenList[tokenNumber];
    }
    void
};