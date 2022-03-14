cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(Compiler main.cpp LexicalAnalyzer/lexical_analyzer.h Resources/tokens.h SyntaxAnalyzer/Parser.h SyntaxAnalyzer/Parsers/ElementParser.h SyntaxAnalyzer/Parser.cpp SyntaxAnalyzer/Parsers/AtomParser.h SyntaxAnalyzer/Parsers/LiteralParser.h SyntaxAnalyzer/Parsers/ListParser.h SyntaxAnalyzer/Parsers/SetqParser.h SyntaxAnalyzer/Parsers/FuncParser.h SyntaxAnalyzer/Parsers/LambdaParser.h SyntaxAnalyzer/Parsers/ProgParser.h SyntaxAnalyzer/Parsers/CondParser.h LexicalAnalyzer/lexical_analyzer.cpp SyntaxAnalyzer/Parsers/WhileParser.h SyntaxAnalyzer/Parsers/ReturnParser.h SyntaxAnalyzer/Parsers/BreakParser.h SyntaxAnalyzer/Parsers/ArithmeticParser.h SyntaxAnalyzer/AST/predicatesNode.h SyntaxAnalyzer/Parsers/OperationOnListParser.h SyntaxAnalyzer/Parsers/ComparisonParser.h SyntaxAnalyzer/Parsers/PredicatesParser.h SyntaxAnalyzer/Parsers/LogicalOpParser.h SyntaxAnalyzer/Parsers/EvalParser.h SyntaxAnalyzer/Parsers/QuoteParser.h SyntaxAnalyzer/Parsers/LiteralListParser.h SyntaxAnalyzer/Nodes/nodeDeclaration.h SyntaxAnalyzer/Nodes/nodeInvocation.h SyntaxAnalyzer/Nodes/node.h SyntaxAnalyzer/Nodes/rootNode.h)
