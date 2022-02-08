#include <SyntaxAnalyzer/Parser.h>
#include <SyntaxAnalyzer/Parsers/ElementParser.h>

rootNode Parser::ProgramParse(std::vector<Token> List) {
    tokenList = List;
    rootNode root = rootNode();
    int tokenNumber = 0;
    while (1) {
        ElementParser elementParser;
        elementParser.Parse(*this, &tokenNumber);
    }
    return root;
}

Token Parser::GetToken(int tokenNumber) {
    if (tokenNumber >= tokenList.size()) {
        ErrorMessage(tokenList.back().line, tokenList.back().position);
        return tokenList.back();
    }
    return tokenList[tokenNumber];
}

void Parser::ErrorMessage(int line, int position) {
    std::cout << "Syntax error at line " << line << ", at position " << position << '\n';
    exit(0);
}