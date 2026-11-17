// Practice problem 1 : evaluate with a stack
// 123+456x–7x+-89x+

#include <iostream>
#include <string>
#include <cctype>
#include "stack.cpp"
using namespace std;

int main(void)
{
    string input;
    cin >> input;

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
            }   
        }
        
    }

    cout << s.peek() << "\n";
}