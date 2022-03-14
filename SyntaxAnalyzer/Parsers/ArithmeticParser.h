#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

#ifndef COMPILER_ARITHMETICPARSER_H
#define COMPILER_ARITHMETICPARSER_H

Node* ArithmeticParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *arithmetic_node = new NodeInvocation();
    Token curToken = parser->GetToken(*tokenNumber);
    (*tokenNumber) ++;

    if (curToken.code == tokPlus) {
        arithmetic_node->setName("plus");
    }
    if (curToken.code == tokMinus) {
        arithmetic_node->setName("minus");
    }
    if (curToken.code == tokDivide) {
        arithmetic_node->setName("divide");
    }
    if (curToken.code == tokTimes) {
        arithmetic_node->setName("times");
    }

    arithmetic_node->addParameter(ElementParser(parser, tokenNumber));
    arithmetic_node->addParameter(ElementParser(parser, tokenNumber));
    return arithmetic_node;
}


#endif //COMPILER_ARITHMETICPARSER_H
