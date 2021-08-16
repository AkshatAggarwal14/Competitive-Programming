#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = nullptr, *last = nullptr;

void Display(Node *p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

/**
 * There are 3 cases:
 * 1. No elements in list: thus first and last both point to NULL
 * 2. There is just one element thus they both point to it
 * 3. They point to different Nodes
*/

void InsertLast(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    if (first == nullptr)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

int main() {
    InsertLast(0);
    InsertLast(12);
    InsertLast(434);
    InsertLast(-3);  //!CONSTANT TIME
    Display(first);

    return 0;
}
