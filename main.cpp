#include <iostream>
using namespace std;


bool isPunctuator(char ch)					//check if the given character is a punctuator or not
{
    if (ch == ' ' || ch == ':' || ch == '(' || ch == ')' || ch == '{' ||
        ch == '}' || ch == '|' || ch == '+' || ch == '-' || ch == '.' )
    {
        return true;
    }
    return false;
}



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
