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
    tokIdentifier,
    tokEndFile,
    tokEndLine
};

struct Token {
    unsigned int code = -1;

    char letterVal;
    int intVal;
    int decVal;
    double realVal;
    std::string idVal;

    int line;
    int position;
};

#endif //COMPILER_TOKENS_H