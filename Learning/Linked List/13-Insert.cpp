#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void Display(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

//to insert we need index, but as no indexes here we can make it 1-indexed
//   8 -> 9 -> 10 -> 11 -> 12
//   1    2    3     4     5
//0    1     2    3     4    5
/*
todo: insert before first node
s1-  create new node
s2- initialise the node with data
s3- make it point to first node
s4- move first from first to new node

todo: insert after given pos (say 4)
s1-  create new node
s2- initialise the node with data
? now a pointer is moved until pos, which needs pos-1 steps (3 here)
? now the new node must point to p->next wali node
? p should point on the new node
*/

void Insert(int pos, int x) {
    if (pos < 0 || pos > 9) return;  //! failsafe

    if (pos == 0) {  //insert before first
        Node *t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    } else {  //insert after first
        Node *t = new Node, *p;
        t->data = x;
        p = first;
        for (int i = 0; i < pos - 1; ++i) p = p->next;
        t->next = p->next;
        p->next = t;
    }
    return;
}

int main() {
    Insert(0, 10);
    Display(first);
    Insert(1, 20);
    Display(first);
    Insert(2, 30);
    Display(first);
    Insert(0, 5);
    Display(first);
    Insert(2, 35);
    Display(first);

    return 0;
}
