#include "Resources/tokens.h"

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

class Node {
public:
    Token token;

    void SetToken(Token token) {
        this->token = token;
    }
};

#endif //COMPILER_TOKENS_H