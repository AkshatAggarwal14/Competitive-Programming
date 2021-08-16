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

//can also be done with one pointer checking data of next node
void Sorted_insert(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if (!first)
        first = t;                //if no node in list insert it
    else if (first->data >= x) {  //*if it can be inserted in beginning
        t->next = first;
        first = t;
    } else {
        Node *p = first, *q = nullptr;
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        //q is the node after which we need to insert
        t->next = p;  // t->next=q->next
        q->next = t;
    }
}

int main() {
    // InsertLast(3);
    // InsertLast(7);
    // InsertLast(9);
    // InsertLast(15);
    // InsertLast(20);
    // Display(first);

    Sorted_insert(18);
    Display(first);

    Sorted_insert(40);
    Display(first);

    Sorted_insert(5);
    Display(first);

    Sorted_insert(1);
    Display(first);

    Sorted_insert(1);
    Display(first);

    return 0;
}
