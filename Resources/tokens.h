#include <string>

#ifndef COMPILER_TOKENS_H
#define COMPILER_TOKENS_H

enum Code {
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
    tokIsInt,
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
    tokInt,
    tokReal,
    tokBoolean,
    tokAtom,
    tokEndFile
};

struct Token {
    unsigned int code = -1;

    int intVal;
    double realVal;
    bool boolVal;
    std::string atomVal;

    int line;
    int position;
};

#endif //COMPILER_TOKENS_H