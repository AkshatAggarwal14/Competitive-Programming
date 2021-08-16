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

int count(Node *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void RemoveDuplicates() {
    // q is node before p
    Node *q = first, *p = first->next;
    for (int i = 0; p; ++i) {
        if (p->data == q->data) {
            q->next = p->next;
            free(p);
            p = q->next;

            Display(first);
        } else {
            q = p;
            p = p->next;
        }
    }
}

int main() {
    InsertLast(5);
    InsertLast(5);
    InsertLast(8);
    InsertLast(8);
    InsertLast(8);
    Display(first);

    RemoveDuplicates();
    // Display(first);

    return 0;
}
