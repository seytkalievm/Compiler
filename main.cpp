#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
#include "LexicalAnalyzer/lexical_analyzer.h"



int main() {
    ifstream sourcecode ("sourcecode.txt");
    int curLine = 1, curChar = 1;
    int cur = 0;
    char peek;
    peek = sourcecode.peek();
    Token tokens[200];

    if (sourcecode.is_open()) {
        while (peek != EOF) {
            tokens[cur] = getNextToken( &sourcecode, &curLine, &curChar);
            cout << to_string(tokens[cur].code) << " ";
            cur++;
            peek = sourcecode.peek();
        }
    }
    sourcecode.close();

    return 0;
}