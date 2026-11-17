// convert to postfix, then evaluate
// (((1+2)x3)-(8/(5-1)))


#include <iostream>
#include <string>
#include <cctype>
#include "stack.cpp"
using namespace std;

int main(void)
{
    stack postfix;
    string input;
    cin >> input;

    string poststring;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ')')
        {
            char x = (char)postfix.peek();
            poststring.push_back(x);
            postfix.pop();
            continue;
        }
        if (input[i] == ' ' || input[i] == '(') continue;
        if (isdigit(input[i])) poststring.push_back(input[i]);
        
        else postfix.push(input[i]);
    }

    input = poststring;
    stack s;

    for (int i  = 0; i < input.size(); i++)
    {
        if (input[i] == ' ') continue;
        if (isdigit(input[i])) s.push(input[i] - '0');

        else {
            int x = s.peek();
            s.pop();
            int y = s.peek();
            s.pop();

            switch(input[i])
            {
                case '+' :
                    s.push(x+y);
                    break;
                case '-' :
                    s.push(y-x);
                    break;
                case 'x' :
                    s.push(y*x);
                    break;
                case '/' :
                    s.push(y/x);
            }   
        }
        
    }

    cout << s.peek() << "\n";
}