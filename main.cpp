#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/Parsers/Parser.h>

using namespace std;

#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H

void NodeWriter(Node* node, string indent = "") {

    cout << indent << node->getName() << "|" << '\n';
    for (int i = 1; i <= node->getName().size(); i++) {
        indent += " ";
    }
    indent += "|";
    for (auto child : node->getParameters()) {
        NodeWriter(child, indent);
    }
}

void NodeChecker(RootNode root) {
    for (auto node : root.nodes) {
        NodeWriter(node);
    }
}

int main() {
    ifstream sourcecode ("sourcecode.txt");

    LexicalAnalyzer lexicalAnalyzer;
    vector<Token> tokenList = lexicalAnalyzer.Analyze(sourcecode);

    for (auto x : tokenList) {
        //cout << x.code << ' ';
    }

    Parser parser;
    auto root = parser.ProgramParse(tokenList);

    //NodeWriter(root);
    return 0;
}

#endif //COMPILER_MAIN_H