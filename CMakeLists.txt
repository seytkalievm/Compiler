cmake_minimum_required(VERSION 3.17)
project(Compiler)

find_package(LLVM REQUIRED CONFIG)
set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

add_executable(Compiler main.cpp LexicalAnalyzer/lexical_analyzer.h Resources/tokens.h 
                SyntaxAnalyzer/Parsers/Parser.h SyntaxAnalyzer/Parsers/ElementParser.cpp 
                            SyntaxAnalyzer/Parsers/Parser.cpp SyntaxAnalyzer/Parsers/AtomParser.cpp 
                                        SyntaxAnalyzer/Parsers/LiteralParser.cpp SyntaxAnalyzer/Parsers/ListParser.cpp 
                                                SyntaxAnalyzer/Parsers/SetqParser.cpp SyntaxAnalyzer/Parsers/FuncParser.cpp 
                                                        SyntaxAnalyzer/Parsers/LambdaParser.cpp SyntaxAnalyzer/Parsers/ProgParser.cpp 
                                                                SyntaxAnalyzer/Parsers/CondParser.cpp LexicalAnalyzer/lexical_analyzer.cpp 
                                                                        SyntaxAnalyzer/Parsers/WhileParser.cpp SyntaxAnalyzer/Parsers/ReturnParser.cpp 
                                                                                SyntaxAnalyzer/Parsers/BreakParser.cpp SyntaxAnalyzer/Parsers/ArithmeticParser.cpp 
                                                                                        SyntaxAnalyzer/Parsers/OperationOnListParser.cpp SyntaxAnalyzer/Parsers/ComparisonParser.cpp 
                                                                                                SyntaxAnalyzer/Parsers/PredicatesParser.cpp SyntaxAnalyzer/Parsers/LogicalOpParser.cpp 
                                                                                                        SyntaxAnalyzer/Parsers/EvalParser.cpp SyntaxAnalyzer/Parsers/QuoteParser.cpp SyntaxAnalyzer/Parsers/LiteralListParser.cpp SyntaxAnalyzer/Nodes/nodeDeclaration.h 
                                                                                                                        SyntaxAnalyzer/Nodes/nodeInvocation.h SyntaxAnalyzer/Nodes/node.h SyntaxAnalyzer/Nodes/rootNode.h SyntaxAnalyzer/Parsers/ParameterParser.cpp SyntaxAnalyzer/Nodes/nodeParameter.h
                Semantic/Cast/Cast.cpp Semantic/Cast/Cast.h Semantic/Context/GlobalContext.h Semantic/Context/FuncContext.h)

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(Compiler ${llvm_libs})