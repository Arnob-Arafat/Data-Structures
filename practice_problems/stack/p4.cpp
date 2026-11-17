// Practice Problem 4 : next greater element: for each item, the first larger item to its right (–1 if none)

#include <iostream>
#include <string>
#include <cctype>
#include "stack.cpp"
using namespace std;

int main(void)
{
    stack s;

    int arr[] = {4, 5, 2, 10, 8};

    
    for (int i = 0; i < 5; i++)
    {
        while(s.peek() < arr[i] && s.size() > 0)
        {
            cout << arr[i] << " ";
            s.pop();
        }
        s.push(arr[i]);
    }

    while(s.peek() != -1){
        cout << -1;
        s.pop();
    }

    cout << endl;

}