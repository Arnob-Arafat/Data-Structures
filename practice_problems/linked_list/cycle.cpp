// Practice Problem 3 : Does the list have a cycle?

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


bool hasCycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
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

    if(hasCycle(head)) cout << "YES" << "\n";
    else cout << "NO\n";

    int cyclic[5] = {10, 20, 30, 40, 50};

    Node *cyclehead = NULL;
    Node *second;
    for (int i = 0; i < 5; i++)
    {
        Node *ptr = newNode(cyclic[i]);
        
        if (i != 0) {
            pichone->next = ptr;
            pichone = ptr;

            if (i == 1)
            {
                second = ptr;
            }
            
        }
        
        else
        {
            pichone = ptr;
            cyclehead = ptr;
        }
    }

    pichone->next = second;

    if(hasCycle(cyclehead)) cout << "YES" << "\n";
    else cout << "NO\n";
}