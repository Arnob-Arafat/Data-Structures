#include <bits/stdc++.h>
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
}