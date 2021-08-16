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
//   8 -> 9 -> 10 -> 11
//   1    2    3     4
//0    1     2    3      4
/*
todo: insert before first node
s1-  create new node
s2- initialise the node with data
s3- make it point to first node
s4- move first from first to new node
*/

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};

    create(A, 9);
    Display(first);

    Node *t = new Node;  //* CONSTANT TIME O(1);
    t->data = 10000;
    t->next = first;
    first = t;

    Display(first);

    return 0;
}
