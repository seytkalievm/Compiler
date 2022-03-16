#include <SyntaxAnalyzer/Parsers/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* QuoteParser(Parser *parser, int *tokenNumber);
Node* SetqParser(Parser *parser, int *tokenNumber);
Node* FuncParser(Parser *parser, int *tokenNumber);
Node* LambdaParser(Parser *parser, int *tokenNumber);
Node* ProgParser(Parser *parser, int *tokenNumber);
Node* CondParser(Parser *parser, int *tokenNumber);
Node* WhileParser(Parser *parser, int *tokenNumber);
Node* ReturnParser(Parser *parser, int *tokenNumber);
Node* BreakParser(Parser *parser, int *tokenNumber);
Node* ArithmeticParser(Parser *parser, int *tokenNumber);
Node* OperationOnListParser(Parser *parser, int *tokenNumber);
Node* ComparisonParser(Parser *parser, int *tokenNumber);
Node* PredicatesParser(Parser *parser, int *tokenNumber);
Node* LogicalOpParser(Parser *parser, int *tokenNumber);
Node* EvalParser(Parser *parser, int *tokenNumber);
Node* ElementParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);


Node* ListParser(Parser *parser, int *tokenNumber){
    (*tokenNumber) ++;
    Token currentToken = parser->GetToken(*tokenNumber);
    Node* element_node;

    if (currentToken.code == tokQuote) {
        element_node = QuoteParser(parser, tokenNumber);
    } else if (currentToken.code == tokSetq) {
        element_node = SetqParser(parser, tokenNumber);
    } else if (currentToken.code == tokFunc) {
        element_node = FuncParser(parser, tokenNumber);
    } else if (currentToken.code == tokLambda) {
        element_node = LambdaParser(parser, tokenNumber);
    } else if (currentToken.code == tokProg) {
        element_node = ProgParser(parser, tokenNumber);
    } else if (currentToken.code == tokCond) {
        element_node = CondParser(parser, tokenNumber);
    } else if (currentToken.code == tokWhile) {
        element_node = WhileParser(parser, tokenNumber);
    } else if (currentToken.code == tokReturn) {
        element_node = ReturnParser(parser, tokenNumber);
    } else if (currentToken.code == tokBreak) {
        element_node = BreakParser(parser, tokenNumber);
    } else if (currentToken.code == tokPlus || currentToken.code == tokMinus ||
               currentToken.code == tokTimes || currentToken.code == tokDivide) {
        element_node = ArithmeticParser(parser, tokenNumber);
    } else if (currentToken.code == tokHead || currentToken.code == tokTail || currentToken.code == tokCons) {
        element_node = OperationOnListParser(parser, tokenNumber);
    } else if (currentToken.code == tokEqual || currentToken.code == tokNonEqual
               || currentToken.code == tokLess || currentToken.code == tokLessEq
               || currentToken.code == tokGreater || currentToken.code == tokGreaterEq) {
        element_node = ComparisonParser(parser, tokenNumber);
    } else if (currentToken.code == tokIsBool || currentToken.code == tokIsAtom
               || currentToken.code == tokIsList || currentToken.code == tokIsNull
               || currentToken.code == tokIsReal || currentToken.code == tokIsInt) {
        element_node = PredicatesParser(parser, tokenNumber);
    } else if (currentToken.code == tokAnd || currentToken.code == tokOr
               || currentToken.code == tokXor || currentToken.code == tokNot) {
        element_node = LogicalOpParser(parser, tokenNumber);
    } else if (currentToken.code == tokEval) {
        element_node = EvalParser(parser, tokenNumber);
    } else if (currentToken.code == tokAtom) {
        currentToken.code = tokFunction;
        NodeInvocation *func_invocation = new NodeInvocation();
        func_invocation->setName(currentToken.value.atomVal);
        (*tokenNumber) ++;
        auto parameters = LiteralListParser(parser, tokenNumber)->getListVal();
        for (auto x : parameters) {
            func_invocation->addParameter(x);
        }
        element_node = func_invocation;
    } else {
        element_node = LiteralListParser(parser, tokenNumber);
    }
    if (parser->GetToken(*tokenNumber).code != tokCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position);
    }
    (*tokenNumber) ++;
    return element_node;
}
