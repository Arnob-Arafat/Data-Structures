// Practice Problem 1 : reverse the list in place: O(n) time, O(1) extra memory


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

    Node *pichone = head;
    for (int i = 0; i < 3; i++)
    {
        Node *ptr = newNode(arr[i]);
        if (i != 0) {
            pichone->next = ptr;
            pichone = ptr;
        }
        else
        {
            pichone = ptr;
            head = ptr;
        }
    }
    Node *ptr = head;

    for (int i = 0; i < 3; i++)
    {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }

    head = prev;
    Node *ptr1 = head;

    for (int i = 0; i < 3; i++)
    {
        cout << ptr1->data << "\n";
        ptr1 = ptr1->next;
    }
}