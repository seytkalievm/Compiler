#include <SyntaxAnalyzer/Parsers/Parser.h>
Node* ElementParser(Parser *parser, int *tokenNumber);

RootNode Parser::ProgramParse(std::vector<Token> List) {
    tokenList = List;
    RootNode root = RootNode();
    int tokenNumber = 0;
    while (tokenNumber < List.size()) {
        root.AddChild(ElementParser(this, &tokenNumber));
    }
    return root;
}

Token Parser::GetToken(int tokenNumber) {
    if (tokenNumber >= tokenList.size()) {
        ErrorMessage(tokenList.back().location.line, tokenList.back().location.position);
        return tokenList.back();
    }
    return tokenList[tokenNumber];
}

void Parser::ErrorMessage(int line, int position) {
    std::cout << "Syntax error at line " << line << ", at position " << position << '\n';
    exit(0);
}