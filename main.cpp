#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/Parsers/Parser.h>
#include <Semantic/Cast/Cast.h>

using namespace std;

#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H

void NodeWriter(Node* node, string indent = "") {

    cout << indent << node->getName() << "(" << node->nodeType << ")|" << '\n';
    for (int i = 1; i <= node->getName().size() + node->nodeType.size() + 2; i++) {
        indent += " ";
    }
    indent += "|";
    for (auto child : node->getParameters()) {
        NodeWriter(child, indent);
    }
    if (node->nodeType == "Declaration") {
        cout << indent << "Expression|" << '\n';
        NodeWriter(node->getExpression(), indent + "          |");
    }
    if (node->nodeType == "Invocation") {
        cout << indent << "Declaration|" << '\n';
        cout << indent << node->getDeclaration()->getName() << '\n'; 
    }
}

void NodeChecker(RootNode root) {
    std::cout << '\n';
    for (auto node : root.nodes) {
        NodeWriter(node);
    }
    std::cout << '\n';
}

void CodeGen(RootNode root) {
    for (auto node : root.nodes) {
        if (node->nodeType == "Invocation") {
            node->codegen()->print(llvm::errs());
            std::cout << '\n';
        }
    }
}

int main() {
    ifstream sourcecode ("/Users/diazzzu/Documents/Compiler/sourcecode.txt");
    
    LexicalAnalyzer lexicalAnalyzer;
    vector<Token> tokenList = lexicalAnalyzer.Analyze(sourcecode);

    for (auto x : tokenList) {
         // cout << x.code << ' ';
    }
    Parser parser;
    auto root = parser.ProgramParse(tokenList);
    
    CastRoot(&root);
    //NodeChecker(root);

    CodeGen(root);
    return 0;
}

#endif //COMPILER_MAIN_H