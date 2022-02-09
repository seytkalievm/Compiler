#include "QuoteParser.h"
#include "SetqParser.h"
#include "FuncParser.h"
#include "LambdaParser.h"
#include "ProgParser.h"
#include "CondParser.h"
#include "WhileParser.h"
#include "ReturnParser.h"
#include "BreakParser.h"
#include "ArithmeticParser.h"
#include "OperationOnListParser.h"
#include "ComparisonParser.h"
#include "PredicatesParser.h"
#include "LogicalOpParser.h"
#include "EvalParser.h"
#include "ElementParser.h"
#include "LiteralListParser.h"
#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parser.h>

elementNode ListParser::Parse(Parser *parser, int *tokenNumber){
    (*tokenNumber) ++;
    Token currentToken = parser->GetToken(*tokenNumber);
    elementNode element_node;

    if (currentToken.code == tokQuote) {
        QuoteParser quoteParser;
        element_node = quoteParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokSetq) {
        SetqParser setqParser;
        element_node = setqParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokFunc) {
        FuncParser funcParser;
        element_node = funcParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokLambda) {
        LambdaParser lambdaParser;
        element_node = lambdaParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokProg) {
        ProgParser progParser;
        element_node = progParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokCond) {
        CondParser condParser;
        element_node = condParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokWhile) {
        WhileParser whileParser;
        element_node = whileParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokReturn) {
        ReturnParser returnParser;
        element_node = returnParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokBreak) {
        BreakParser breakParser;
        element_node = breakParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokPlus || currentToken.code == tokMinus ||
                            currentToken.code == tokTimes || currentToken.code == tokDivide) {
        ArithmeticParser arithmeticParser;
        element_node = arithmeticParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokHead || currentToken.code == tokTail || currentToken.code == tokCons) {
        OperationOnListParser operationOnListParser;
        element_node = operationOnListParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokEqual || currentToken.code == tokNonEqual
                    || currentToken.code == tokLess || currentToken.code == tokLessEq
                                || currentToken.code == tokGreater || currentToken.code == tokGreaterEq) {
        ComparisonParser comparisonParser;
        element_node = comparisonParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokIsBool || currentToken.code == tokIsAtom
                    || currentToken.code == tokIsList || currentToken.code == tokIsNull
                            || currentToken.code == tokIsReal || currentToken.code == tokIsInt) {
        PredicatesParser predicatesParser;
        element_node = predicatesParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokAnd || currentToken.code == tokOr
                    || currentToken.code == tokXor || currentToken.code == tokNot) {
        LogicalOpParser logicalOpParser;
        element_node = logicalOpParser.Parse(parser, tokenNumber);
    } else if (currentToken.code == tokEval) {
        EvalParser evalParser;
        element_node = evalParser.Parse(parser, tokenNumber);
    } else {
        LiteralListParser literalListParser;
        element_node = literalListParser.Parse(parser, tokenNumber);
    }

    if (parser->GetToken(*tokenNumber).code != tokCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).line, parser->GetToken(*tokenNumber).position);
    }
    (*tokenNumber) ++;
    return element_node;
}