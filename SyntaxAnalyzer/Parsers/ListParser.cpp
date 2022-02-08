#include <SyntaxAnalyzer/Parsers/ListParser.h>
#include <SyntaxAnalyzer/Parser.h>

listNode ListParser::Parse(Parser parser, int *tokenNumber){
    tokenNumber ++;
    Token currentToken = parser.GetToken(*tokenNumber);
    listNode list_node;
    if (currentToken.code == tokQuote) {

    } else if (currentToken.code == tokSetq) {

    } else if (currentToken.code == tokFunc) {

    } else if (currentToken.code == tokLambda) {

    } else if (currentToken.code == tokProg) {

    } else if (currentToken.code == tokQuote) {

    } else if (currentToken.code == tokCond) {

    } else if (currentToken.code == tokWhile) {

    } else if (currentToken.code == tokReturn) {

    } else if (currentToken.code == tokBreak) {

    } else if (currentToken.code == tokPlus) {

    } else if (currentToken.code == tokMinus) {

    } else if (currentToken.code == tokTimes) {

    } else if (currentToken.code == tokDivide) {

    } else if (currentToken.code == tokHead) {

    } else if (currentToken.code == tokTail) {

    } else if (currentToken.code == tokCons) {

    } else if (currentToken.code == tokEqual) {

    } else if (currentToken.code == tokNonEqual) {

    } else if (currentToken.code == tokLess) {

    } else if (currentToken.code == tokLessEq) {

    } else if (currentToken.code == tokGreater) {

    } else if (currentToken.code == tokGreaterEq) {

    } else if (currentToken.code == tokIsBool) {

    } else if (currentToken.code == tokIsAtom) {

    } else if (currentToken.code == tokIsList) {

    } else if (currentToken.code == tokIsNull) {

    } else if (currentToken.code == tokIsReal) {

    } else if (currentToken.code == tokIsInt) {

    } else if (currentToken.code == tokAnd) {

    } else if (currentToken.code == tokOr) {

    } else if (currentToken.code == tokXor) {

    } else if (currentToken.code == tokNot) {

    } else if (currentToken.code == tokEval) {

    }

    return list_node;
}