#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/node.h>
#include <SyntaxAnalyzer/AST/rootNode.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

class Parser {
    std::vector<Token> tokenList;
public:
    rootNode ProgramParse(std::vector<Token> List) {
        tokenList = List;
        rootNode root = rootNode();
        int tokenNumber = 0;
        while (1) {
            ParseElement(this, &tokenNumber);
        }
        return root;
    }
    Token GetToken(int tokenNumber) {
        if (tokenNumber >= tokenList.size()) {
            ErrorMessage(tokenList.back().line, tokenList.back().position);
            return tokenList.back();
        }
        return tokenList[tokenNumber];
    }
    void ErrorMessage(int line, int position) {
        std::cout << "Syntax error at line " << line << ", at position " << position << '\n';
        exit(0);
    }
};

#endif //COMPILER_PARSER_H