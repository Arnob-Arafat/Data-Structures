// Practice Problem 5 : remove the k-th node from the end in one pass (k = 1: the last node)

#include <iostream>
using namespace std;

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

    int arr[6] = {10, 20, 30, 40, 50, 60};

    Node *pichone = head;
    for (int i = 0; i < 6; i++)
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

    for (int i = 0; i < 6; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;

    int k = 2;

    Node *beforek = head;
    Node *afterk = head->next->next;

    Node *last = head;

    while(k--) last = last->next;

    while(last->next != NULL)
    {
        beforek = beforek->next;
        afterk = afterk->next;
        last = last->next;
    }

    Node *temp = beforek->next;
    

    beforek->next = afterk;
    
    delete temp;

    Node *ptr0 = head;

    for (int i = 0; i < 5; i++)
    {
        cout << ptr0->data << " ";
        ptr0 = ptr0->next;
    }

    cout << endl;

}