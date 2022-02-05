#include <string>
#include <fstream>
#include <cstring>
#include <vector>

#include <Resources/tokens.h>

Token getNextToken(std::ifstream *file, int *curLine, int *curPos){
    Token token;
    char c;
    const char *tok;
    int startPos = 0;
    int endPos = 0;

    std::string tokenLetters = "";

    while(file->peek() == ' ' || file->peek() == '\n'){
        startPos++;
        endPos++;
        curPos++;
        if(file->peek() == '\n') {
            (*curPos) = 1;
            (*curLine) ++;
        }
        file->get(c);
    }

    token.position = *curPos;
    token.line = *curLine;
    if (file->peek() == EOF) {
        token.code = tokEndFile;
        return token;
    }

    tokenLetters += file->get();

    if(tokenLetters != "(" && tokenLetters != ")" && tokenLetters != "[" && tokenLetters != "]" && tokenLetters != "\'" && tokenLetters != "/" && tokenLetters != "\n") {
        while (file->peek() != ' ' && file->peek() != '(' && file->peek() != ')' && file->peek() != '[' && file->peek() != ']' && file->peek() != EOF && file->peek() != '\n') {
            tokenLetters += file->get();
            endPos++;
            curPos++;
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
    } else if (tokenLetters == "nonequal") {
        token.code = tokNonEqual;
    } else if (tokenLetters == "less") {
        token.code = tokLess;
    } else if (tokenLetters == "lesseq") {
        token.code = tokLessEq;
    } else if (tokenLetters == "greater") {
        token.code = tokGreater;
    } else if (tokenLetters == "greatereq") {
        token.code = tokGreaterEq;
    } else if (tokenLetters == "isint") {
        token.code = tokIsint;
    } else if (tokenLetters == "isreal") {
        token.code = tokIsReal;
    } else if (tokenLetters == "isbool") {
        token.code = tokIsBool;
    } else if (tokenLetters == "isnull") {
        token.code = tokIsNull;
    } else if (tokenLetters == "isatom") {
        token.code = tokIsAtom;
    } else if (tokenLetters == "islist") {
        token.code = tokIsList;
    } else if (tokenLetters == "and") {
        token.code = tokAnd;
    } else if (tokenLetters == "or") {
        token.code = tokOr;
    } else if (tokenLetters == "xor") {
        token.code = tokXor;
    } else if (tokenLetters == "not") {
        token.code = tokNot;
    } else if (tokenLetters == "true") {
        token.code = tokTrue;
    } else if (tokenLetters == "false") {
        token.code = tokFalse;
    } else if (tokenLetters == "plus") {
        token.code = tokPlus;
    } else if (tokenLetters == "minus") {
        token.code = tokMinus;
    } else if (tokenLetters == "times") {
        token.code = tokTimes;
    } else if (tokenLetters == "divide") {
        token.code = tokDivide;
    } else if (tokenLetters == "head") {
        token.code = tokHead;
    } else if (tokenLetters == "tail") {
        token.code = tokTail;
    } else if (tokenLetters == "cons") {
        token.code = tokCons;
    } else if (tokenLetters == "eval") {
        token.code = tokEval;
    } else if (tokenLetters.size() == 1) {
        if(isdigit(tok[0])){
            token.code = tokDec;
            token.decVal = std::stoi(tok);
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
    return token;
}

std::vector<Token> Analyze(std::ifstream& sourcecode) {
    int curLine = 1, curPos = 0;
    int cur = 0;
    char peek = sourcecode.peek();
    std::vector < Token > tokensList;

    if (sourcecode.is_open()) {
        while (peek != EOF) {
            tokensList.push_back(getNextToken( &sourcecode, &curLine, &curPos));
            cur++;
            peek = sourcecode.peek();
        }
    }
    sourcecode.close();
    return tokensList;
}