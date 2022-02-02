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
    tokIdentifier,
    tokEndFile
};


struct Token{
    unsigned int code = -1;
    char letterVal = -1;
    int intVal = -1;
    int decVal = -1;
    double realVal = -1;
    string idVal;
};