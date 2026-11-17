#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *newNode(int x)
{
    Node *p = new Node; // C: struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}


class stack{
    public:

    Node *top = NULL;
    int len = 0;

    void push(int x)
    {
        Node *newtop = newNode(x);

        if(top == NULL) top = newtop;
        else
        {
            newtop->next = top;
            top = newtop;
        }
        len++;
    }

    void pop()
    {
        Node *temp = top;
        top = top->next;
        len--;

        delete temp;
    }

    int peek()
    {
        if (top == NULL) return -1;
        
        return top->data;
    }

    int size(){
        return len;
    }

};