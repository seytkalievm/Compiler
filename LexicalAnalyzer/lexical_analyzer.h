#include <string>
#include <fstream>
#include <cstring>

#include <Resources/tokens.h>

Token getNextToken(ifstream *file, const int *curLine, const int*curChar){
    Token token;
    char c;
    const char *tok;
    int startPos = 0;
    int endPos = 0;
    char buff [200] = "";

    string tokenLetters = "";

    while(file->peek() == ' ' || file->peek() == '\n'){
        startPos++;
        endPos++;
        file->get(c);
    }

    if (file->peek() == EOF) {
        token.code = tokEndFile;
        return token;
    }

    tokenLetters += file->get();

    if(tokenLetters != "(" && tokenLetters != ")" && tokenLetters != "[" && tokenLetters != "]" && tokenLetters != "\'" && tokenLetters != "/") {
        while (file->peek() != ' ' && file->peek() != '(' && file->peek() != ')' && file->peek() != '[' &&
               file->peek() != ']' && file->peek() != EOF) {
            tokenLetters += file->get();
            endPos++;
        }
    }

    if (tokenLetters == "(") {
        token.code = tokOpenParenthesis;
    } else if (tokenLetters == ")") {
        token.code = tokCloseParenthesis;
    } else if (tokenLetters == "[") {
        token.code = tokOpenBracket;
    } else if (tokenLetters == "]") {
        token.code = tokCloseBracket;
    } else if (tokenLetters == "\'") {
        token.code = tokQuote;
    } else if (tokenLetters == "/") {
        token.code = tokSlash;
    } else if (tokenLetters == "setq") {
        token.code = tokSetq;
    } else if (tokenLetters == "func") {
        token.code = tokFunc;
    } else if (tokenLetters ==  "lambda") {
        token.code = tokLambda;
    } else if (tokenLetters == "prog") {
        token.code = tokProg;
    } else if (tokenLetters == "cond") {
        token.code = tokCond;
    } else if (tokenLetters == "while") {
        token.code = tokWhile;
    } else if (tokenLetters == "return") {
        token.code = tokReturn;
    } else if (tokenLetters == "break") {
        token.code = tokBreak;
    } else if (tokenLetters == "equal") {
        token.code = tokEqual;
    } else if (tokenLetters == "nonequal" ) {
        token.code = tokNonEqual;
    } else if (tokenLetters == "less" ) {
        token.code = tokLess;
    } else if (tokenLetters == "lesseq") {
        token.code = tokLessEq;
    } else if (tokenLetters == "greater") {
        token.code = tokGreater;
    } else if (tokenLetters == "greatereq" ) {
        token.code = tokGreaterEq;
    } else if (tokenLetters == "isint" ) {
        token.code = tokIsint;
    } else if (tokenLetters == "isreal" ) {
        token.code = tokIsReal;
    } else if (tokenLetters == "isbool" ) {
        token.code = tokIsBool;
    } else if (tokenLetters == "isnull" ) {
        token.code = tokIsNull;
    } else if (tokenLetters == "isatom" ) {
        token.code = tokIsAtom;
    } else if (tokenLetters == "islist" ) {
        token.code = tokIsList;
    } else if (tokenLetters == "and" ) {
        token.code = tokAnd;
    } else if (tokenLetters == "or" ) {
        token.code = tokOr;
    } else if (tokenLetters == "xor" ) {
        token.code = tokXor;
    } else if (tokenLetters == "not" ) {
        token.code = tokNot;
    } else if (tokenLetters == "true" ) {
        token.code = tokTrue;
    } else if (tokenLetters == "false" ) {
        token.code = tokFalse;
    } else if (tokenLetters == "plus" ) {
        token.code = tokPlus;
    } else if (tokenLetters == "minus" ) {
        token.code = tokMinus;
    } else if (tokenLetters == "times" ) {
        token.code = tokTimes;
    } else if (tokenLetters == "divide" ) {
        token.code = tokDivide;
    } else if (tokenLetters == "head" ) {
        token.code = tokHead;
    } else if (tokenLetters == "tail" ) {
        token.code = tokTail;
    } else if (tokenLetters == "cons" ) {
        token.code = tokCons;
    } else if (tokenLetters == "eval" ) {
        token.code = tokEval;
    } else if (tokenLetters.size() == 1) {
        if(isdigit(tok[0])){
            token.code = tokDec;
            token.decVal = stoi(tok);
        } else{
            token.code = tokLetter;
            token.letterVal = tok[0];
        }
    } else if(isdigit(tokenLetters[0]))  {
        bool real = false;
        for (int i = 0; i < tokenLetters.size(); i++) {
            if (tokenLetters[i] == '.'){
                real = true;
            }

            if(real) {
                token.code = tokReal;
                token.realVal = stod(tokenLetters);
            } else {
                token.code = tokInt;
                token.realVal = stoi(tokenLetters);
            }
        }
    } else {
        token.code = tokIdentifier;
        token.idVal = tokenLetters;
    }
    curChar += endPos;
    return token;
    
}