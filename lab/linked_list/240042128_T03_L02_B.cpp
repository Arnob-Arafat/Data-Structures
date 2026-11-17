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

    int n, k;

    cin >> n >> k;

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

    Node *leads[k];
    Node *curr =  head;


    /*
    I could not really find a alternative way to connect lets
    say 107 to 102 as my pointer to 102 is lost during traversal 
    and there is nothing pointing to 102. Again I think i cannot 
    just take a single pointer to 102 i.e. the second lead i also 
    need other pointers for the other leads except the first one

    I think there may be better alternatives for this problems, but
    this is the best i could think of as of this moment :))
    */
   
    for (int i = 0; i < k; i++)
    {
        leads[i] = curr;
        curr = curr->next;
    }

    leads[0] = NULL;

    // for (int i = 0; i < k; i++)
    // {
    //     cout << leads[i] << endl;
    // }

    Node *lead = head;
    Node *nextLead = head;

    for (int i = 0; i < n; i++)
    {
        nextLead = lead->next;
        if (i+k >= n)
        {
            lead->next = leads[((i+1)%k)];
        }
        else {
            lead->next = curr;
            curr = curr->next;
        }
        lead = nextLead;
    }

    Node *read = head;
    while(read != NULL) {
        cout << read->data << " ";
        read = read->next;
    }
    cout << endl;
}