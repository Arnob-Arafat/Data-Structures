// Practice Problem 3 : circular queue, MAX = 4: enqueue 1, 2, 3, then dequeue twice, then enqueue 4, 5, 6

#include <iostream>
using namespace std;
#define MAX 4

template <typename T>
class queue
{
    T arr[MAX];
    int front = 0;
    int rear =  0;

    public:
    void enqueue(T x)
    {
        arr[rear] = x;
        if (front != (rear+1)%MAX) rear = (rear+1)%MAX;
        else
        {
            cout << "FULL" << "\n";
        }
    }

    void dequeue()
    {
        T x = arr[front];
        if (rear != (front+1)%MAX) front = (front+1)%MAX;
        else
        {
            cout << "empty" << "\n";
            return;
        }
        
        cout << x << "\n";
    }

    bool isEmpty()
    {
        if (front == rear)  return true;
        return false;
    }
};

int main(void)
{
    queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.dequeue();

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
}