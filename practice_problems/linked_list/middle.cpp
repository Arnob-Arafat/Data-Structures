// Practice Problem 2 : the middle node in one pass, no counting first


#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *newNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}


int main(void)
{
    Node *head = NULL;

    int arr[3] = {10, 20, 30};

    Node *prev = head;
    for (int i = 0; i < 3; i++)
    {
        Node *ptr = newNode(arr[i]);
        if (i != 0) {
            prev->next = ptr;
        }
        else
        {
            head = ptr;
        }

        prev = ptr;
    }
    Node *ptr = head;
    
    for (int i = 0; i < 3; i++)
    {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }

    Node *middle = head;
    Node *last = head;

    while(last->next != NULL)
    {
        middle = middle->next;
        last = last->next;
        last = last->next;
    }

    cout << middle->data << "\n";
}