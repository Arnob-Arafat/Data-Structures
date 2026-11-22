// Practice Problem 2 : palindrome check with a deque: racecar, level, abca

#include <iostream>
#include <deque>
using namespace std;


bool isPalindrome(deque<char> d)
{
    while(true)
    {
        if (!(d.front() == d.back())) return false;
        d.pop_back();
        if (d.empty()) break; 
        d.pop_front();
    }
    return true;
}

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        string input;
        cin >> input;

        deque<char> d;

        for (int i = 0; i < (int)input.size(); i++)
        {
            d.push_back(input[i]);
        }

        if(isPalindrome(d)) cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
}