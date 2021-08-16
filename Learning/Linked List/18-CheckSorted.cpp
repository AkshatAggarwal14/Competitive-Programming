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

int count(struct Node *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

bool is_Sorted(Node *p) {  //O(n)
    int x = INT_MIN;

    while (p) {
        if (p->data < x) return false;
        x = p->data;
        p = p->next;
    }

    return true;
}

int main() {
    InsertLast(3);
    InsertLast(7);
    InsertLast(4);
    InsertLast(15);
    InsertLast(20);
    Display(first);

    if (is_Sorted(first))
        cout << "Sorted";
    else
        cout << "Not Sorted";

    return 0;
}
