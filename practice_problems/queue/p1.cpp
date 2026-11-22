// Practice Problem 1: a queue from two stacks in and out

#include <iostream>
#include <stack>
using namespace std;


class queue
{
    stack<int> DownUp;
    stack<int> UpDown;

    public:
    void enqueue(int x) 
    {
        UpDown.push(x);
    }

    int dequeue()
    {
        while(!UpDown.empty())
        {
            DownUp.push(UpDown.top());
            UpDown.pop();
        }

        int res = DownUp.top();
        DownUp.pop();

        while(!DownUp.empty())
        {
            UpDown.push(DownUp.top());
            DownUp.pop();
        }
       
        return res;
    }

    bool isEmpty()
    {
        if(UpDown.empty()) return true;
        return false;
    }

};


int main(void)
{
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    while(!q.isEmpty()) cout << q.dequeue() << " ";

    cout << "\n";
}