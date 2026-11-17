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

void addfront(Node *&head, Node *newhead)
{
    if(head == NULL) {
        head = newhead;
        head->next = NULL;
        //cout << head << " " << newhead << " " << head->data << " " << head->next << endl;
        return;
    }

    Node * temp = head;
    head = newhead;
    head->next = temp;
}

void push(Node *&head, Node *newtail)
{
    if (head == NULL) {
        head = newtail;
        head->next = NULL;
        return;
    }

    Node *tail = head;

    while(tail->next != NULL) tail = tail->next;

    tail->next = newtail;
    newtail->next = NULL;
}

void insert(Node *&head, int k, Node *element)
{
    if (k == 1) {
        Node *temp = head;
        head = element;
        head->next = temp;
    }
    if (head == NULL) return;
    Node *beforek = head;
    Node *afterk = head->next;

    int i = 1;
    for (int i = 1; i < k-1; i++)
    {
        if (beforek == NULL) return;
        beforek = beforek->next;
        afterk = afterk->next;
    }

    beforek->next = element;
    element->next = afterk;
}

void removeAt(Node *&head, int k)
{
    Node *beforek;
    Node *knode;
    
    if (head != NULL) beforek = head; else return;
    if (k == 1){
        knode = head;
        head = head->next;
        delete knode;
        return;
    }

    if (head->next != NULL) knode = head->next; else return;
    if (k == 2){
        knode = head->next;
        head = head->next->next;
        delete knode;
        return;
    }

    for (int i = 0; i < k-1; i++)
    {
        if (knode == NULL) return;
        beforek = beforek->next;
        knode = knode->next;
    }

    beforek->next = beforek->next->next;
    delete knode;
}

void removeVal(Node *&head, int value)
{
    
    if (head == NULL) return;
    
    Node *beforek = head;

    if (head->next == NULL) return;
    
    if (head->next->data == value){
        head = head->next;
        delete beforek;
    }

    Node *knode = head->next;

    while(knode->data != value)
    {
        if (knode == NULL) return;
        beforek = beforek->next;
        knode = knode->next;
        //afterk = afterk->next;
    }

    beforek->next = beforek->next->next;
    delete knode;
}

void printAt(Node *&head, int value)
{
    Node *knode = head;

    if (knode == NULL){
        return;
    }

    int i = 1;

    while(knode->data != value)
    {
        if (knode->next == NULL) {
            cout << 0 << "\n";
            return;
        }
        knode = knode->next;
        i++;
    }

    cout << i << "\n";
}

void printAll(Node *&head)
{
    Node *ptr = head;

    if (ptr == NULL){
       cout << "empty" << endl; 
       return;
    } 


    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main(void)
{
    Node *head = NULL;

    int n;
    cin >> n;

    char action;
    int x, y;
    while(n--)
    {
        cin >> action;

        if (action == 'B'){
            cin >> x;
            push(head, newNode(x));
        }
        else if (action == 'F'){
            cin >> x;
            addfront(head, newNode(x));
        }
        else if (action == 'I'){
            cin >> x >> y;
            insert(head, x, newNode(y));
        }
        else if (action == 'R'){
            cin >> x;
            removeAt(head, x);
        }
        else if (action == 'D'){
            cin >> x;
            removeVal(head, x);
        }
        else if (action == 'S'){
            cin >> x;
            printAt(head, x);
        }
        else if (action == 'P'){
            printAll(head);
        }
    }

}