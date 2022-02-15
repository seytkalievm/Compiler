#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/AST/rootNode.h>
#include <SyntaxAnalyzer/Parser.h>

using namespace std;

#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H

void NodeWriter(Node root, string indent = "") {
    if (indent == "") {
        cout << "root|\n";
        indent += "    |";
    } else {
        cout << indent << Code(root.token.code) << "|" << '\n';
        for (int i = 1; i <= to_string(root.token.code).size(); i++) {
            indent += " ";
        }
        indent += "|";
    }
    for (auto child : root.children) {
        NodeWriter(child, indent);
    }
}

int main() {
    ifstream sourcecode ("sourcecode.txt");

    LexicalAnalyzer lexicalAnalyzer;
    vector<Token> tokenList = lexicalAnalyzer.Analyze(sourcecode);

    Parser parser;
    Node root = parser.ProgramParse(tokenList);
    NodeWriter(root);
    return 0;
}

#endif //COMPILER_MAIN_H