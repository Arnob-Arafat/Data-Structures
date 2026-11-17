#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next; // C: struct Node *next;
};

Node *newNode(int x)
{
    Node *p = new Node; // C: struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}


int main(void)
{
    Node *head = NULL;

    int n, m;

    cin >> n >> m;

    int x;

    Node *ptr = NULL;
    Node *prev = NULL;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if(i == 0)
        {
            head = newNode(x);
            prev = head;
            continue;
        }
        ptr = newNode(x);
        prev->next = ptr;

        prev = ptr;
        ptr = ptr->next;
    }

    Node *boroKhujbe = head;
    prev = head;

    // edge case
    int itrbeforenull = 1;
    int copy = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> x;

        while(boroKhujbe != NULL && boroKhujbe->data < x)
        {
            prev = boroKhujbe;
            boroKhujbe = boroKhujbe->next;
        }

        itrbeforenull++;

        if (boroKhujbe == NULL) {
            prev->next = newNode(x);
            boroKhujbe = prev->next;
            break;
        }

        if (boroKhujbe->data == x) {
            copy++;
            continue;
        }

        if (boroKhujbe == head){
            Node *temp = newNode(x);
            head = temp;
            head->next = boroKhujbe;
            continue;
        }

        // insert
        Node *temp = newNode(x);
        prev->next = temp;
        temp->next = boroKhujbe;
    }

    while(itrbeforenull < m){
        cin >> x;
        boroKhujbe->next = newNode(x);
        boroKhujbe = boroKhujbe;
    }

    cout << n+m-copy << endl;

    Node *read = head;

    while(read != NULL) {
        cout << read->data << " ";
        read = read->next;
    }
    cout << endl;
}