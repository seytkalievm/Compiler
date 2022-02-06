cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(Compiler main.cpp LexicalAnalyzer/lexical_analyzer.h SyntaxAnalyzer/node.h Resources/tokens.h SyntaxAnalyzer/AST/quoteNode.h SyntaxAnalyzer/AST/setqNode.h SyntaxAnalyzer/AST/funcNode.h SyntaxAnalyzer/AST/lambdaNode.h SyntaxAnalyzer/AST/progNode.h SyntaxAnalyzer/AST/condNode.h SyntaxAnalyzer/AST/whileNode.h SyntaxAnalyzer/AST/returnNode.h SyntaxAnalyzer/AST/breakNode.h SyntaxAnalyzer/AST/atomNode.h SyntaxAnalyzer/AST/literalNode.h SyntaxAnalyzer/AST/listNode.h SyntaxAnalyzer/AST/elementNode.h SyntaxAnalyzer/AST/arithmeticNode.h SyntaxAnalyzer/AST/comparisonNode.h SyntaxAnalyzer/AST/predicates.h SyntaxAnalyzer/AST/logicalOpNode.h SyntaxAnalyzer/AST/evaluatorNode.h SyntaxAnalyzer/AST/operationListNode.h SyntaxAnalyzer/Parser.h SyntaxAnalyzer/AST/rootNode.h SyntaxAnalyzer/Parsers/ElementParser.h SyntaxAnalyzer/Parsers/quoteParser.h)
