#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return;
}

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
todo: insert after given pos (say 4)
s1-  create new node
s2- initialise the node with data
? now a pointer is moved until pos, which needs pos-1 steps (3 here)
? now the new node must point to p->next wali node
? p should point on the new node
*/

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};
    int pos = 9;  //to insert element after pos

    create(A, 9);
    Display(first);

    cout << "Enter position to insert node after: ";
    cin >> pos;

    Node *t = new Node, *p;
    t->data = 10000;
    p = first;
    for (int i = 0; i < pos - 1; ++i) {  // O(n) time
        p = p->next;
    }
    t->next = p->next;  //! 2 links are modified
    p->next = t;

    Display(first);

    return 0;
}
