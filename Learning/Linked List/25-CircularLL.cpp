// a linked list in which last node points to first node is called circular linked list
// when collection of nodes is circularly connected -- so no first
// "head" pointer is used for any one of the node <more suitable than first>
//? benefit is: we can traverse circularly
//* Circular singly linked list

//? if only one node it points to itself and is head
//? if zero nodes, head is null
//! how to differentiate between pointer to LL and pointer to circular LL
//? empty should also be circular
// so we use a node as head and circular connect all others
// so now for one, head points to first node which points to itself
// if no nodes at all, head points to itself

//# thus two representations for a circular LL

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;
} *head = nullptr;

void create(vector<int> A) {
    int n = A.size();
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; ++i) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *k) {
    // while (p != head) { //!but first time p == head soooo this is a problem
    //     cout << p->data << " ";
    //     p = p->next;
    // }
    Node *p = k;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << '\n';
}

void R_Display(Node *p) {  //recursive

    static int flag = 0;  // one single copy of flag for all calls

    //! but on first pass this is true
    if (p != head || flag == 0) {
        flag = 1;
        cout << p->data << " ";
        Display(p->next);
    }

    flag = 0;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    create(A);

    Display(head);
    R_Display(head);

    return 0;
}