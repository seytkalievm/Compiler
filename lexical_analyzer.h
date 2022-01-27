#include <string>
#include <fstream>
#include <cstring>

#ifndef COMPILER_LEXICAL_ANALYZER_H
#define COMPILER_LEXICAL_ANALYZER_H

#endif //COMPILER_LEXICAL_ANALYZER_H

enum Code{
    tokOpenParenthesis,
    tokCloseParenthesis,
    tokOpenBracket,
    tokCloseBracket,
    tokSlash,
    tokQuote,
    tokSetq,
    tokFunc,
    tokLambda,
    tokProg,
    tokCond,
    tokWhile,
    tokReturn,
    tokBreak,
    tokEqual,
    tokNonEqual,
    tokLess,
    tokLessEq,
    tokGreater,
    tokGreaterEq,
    tokIsint,
    tokIsReal,
    tokIsBool,
    tokIsNull,
    tokIsAtom,
    tokIsList,
    tokAnd,
    tokOr,
    tokXor,
    tokNot,
    tokTrue,
    tokFalse,
    tokPlus,
    tokMinus,
    tokTimes,
    tokDivide,
    tokHead,
    tokTail,
    tokCons,
    tokEval,
    tokLetter,
    tokInt,
    tokDec,
    tokReal,
    tokIdentifier
};

struct Span{
    int line = -1;
    int starPos = -1;
    int endPos = -1;
};


struct Token{
    Span span;
    unsigned int code = -1;
    char letterVal = -1;
    int intVal = -1;
    int decVal = -1;
    double realVal = -1;
    string idVal;
};

Token getNextToken(ifstream *file, const int *curLine, const int*curChar){
    Token token;
    char c;
    const char *tok;
    int cur = 0;
    char buff [200] = "";
    file->get(c);

    while(c == ' ' || c == '\n'){
        file->get(c);
    }

    switch (c) {
        case '(':
            token.code = tokOpenParenthesis;
            break;

        case ')':
            token.code = tokCloseParenthesis;
            break;

        case '[':
            token.code = tokOpenBracket;
            break;

        case ']':
            token.code = tokCloseBracket;
            break;

        case '\'':
            token.code = tokQuote;
            break;

        case '/':
            token.code = tokSlash;
            break;

        default:
            char next = file->peek();
            buff[cur] = c;
            while (next != ' ' && next != '(' && next != ')' && next != '[' && next != ']'){
                buff[cur] = c;
                file->get(c);
                next = file->peek();
                cur++;
            }
            buff[cur] = c;
            tok = buff;
            if (strcmp(tok, "setq" )==0)
                token.code = tokSetq;
            else if (strcmp(tok, "func" )==0)
                token.code = tokFunc;
            else if (strcmp(tok, "lambda" )==0)
                token.code = tokLambda;
            else if (strcmp(tok, "prog" )==0)
                token.code = tokProg;
            else if (strcmp(tok, "cond" )==0)
                token.code = tokCond;
            else if (strcmp(tok, "while" )==0)
                token.code = tokWhile;
            else if (strcmp(tok, "return" )==0)
                token.code = tokReturn;
            else if (strcmp(tok, "break" )==0)
                token.code = tokBreak;
            else if (strcmp(tok, "equal" )==0)
                token.code = tokEqual;
            else if (strcmp(tok, "nonequal" )==0)
                token.code = tokNonEqual;
            else if (strcmp(tok, "less" )==0)
                token.code = tokLess;
            else if (strcmp(tok, "lesseq" )==0)
                token.code = tokLessEq;
            else if (strcmp(tok, "greater" )==0)
                token.code = tokGreater;
            else if (strcmp(tok, "greatereq" )==0)
                token.code = tokGreaterEq;
            else if (strcmp(tok, "isint" )==0)
                token.code = tokIsint;
            else if (strcmp(tok, "isreal" )==0)
                token.code = tokIsReal;
            else if (strcmp(tok, "isbool" )==0)
                token.code = tokIsBool;
            else if (strcmp(tok, "isnull" )==0)
                token.code = tokIsNull;
            else if (strcmp(tok, "isatom" )==0)
                token.code = tokIsAtom;
            else if (strcmp(tok, "islist" )==0)
                token.code = tokIsList;
            else if (strcmp(tok, "and" )==0)
                token.code = tokAnd;
            else if (strcmp(tok, "or" )==0)
                token.code = tokOr;
            else if (strcmp(tok, "xor" )==0)
                token.code = tokXor;
            else if (strcmp(tok, "not" )==0)
                token.code = tokNot;
            else if (strcmp(tok, "true" )==0)
                token.code = tokTrue;
            else if (strcmp(tok, "false" )==0)
                token.code = tokFalse;
            else if (strcmp(tok, "plus" )==0)
                token.code = tokPlus;
            else if (strcmp(tok, "minus" )==0)
                token.code = tokMinus;
            else if (strcmp(tok, "times" )==0)
                token.code = tokTimes;
            else if (strcmp(tok, "divide" )==0)
                token.code = tokDivide;
            else if (strcmp(tok, "head" )==0)
                token.code = tokHead;
            else if (strcmp(tok, "tail" )==0)
                token.code = tokTail;
            else if (strcmp(tok, "cons" )==0)
                token.code = tokCons;
            else if (strcmp(tok, "eval" )==0)
                token.code = tokEval;


            else if (strlen(tok) == 1){
                if(isdigit(tok[0])){
                    token.code = tokDec;
                    token.decVal = stoi(tok);
                }else{
                    token.code = tokLetter;
                    token.letterVal = tok[0];
                }
            }

            else if(isdigit(tok[0])){
                bool real = false;
                for (int i = 0; i < strlen(tok); i++){
                    if (tok[i] == '.'){
                        real = true;
                    }
                    if(real){
                        token.code = tokReal;
                        token.realVal = stod(tok);
                    } else{
                        token.code = tokInt;
                        token.realVal = stoi(tok);
                    }
                }
            }

            else{
                token.code = tokIdentifier;
                token.idVal = tok;
            }

    }
    token.span.line = *curLine;
    token.span.starPos = *curChar;
    token.span.endPos = *curChar + cur;

    return token;
    
}