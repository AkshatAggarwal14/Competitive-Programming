#include <assert.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void create(int A[], int n, Node *f) {
    assert(n > 0);
    int i;
    struct Node *t, *last;
    f->data = A[0];
    f->next = nullptr;
    last = f;
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
    return;
}

void Display(Node *p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

int count(Node *p) {
    int cnt = 0;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*
    concatenation means appending one to other, join them, like in string s1+s2
    The last node of first1 should point to first2
*/

void concat(Node *first, Node *second) {  //concats second to first
    Node *p = first;                      //* extra pointer needed and O(n) time
    while (p->next) {                     //takes us to last node of first1
        p = p->next;
    }
    p->next = second;
    second = nullptr;
}

int main() {
    Node *first = new Node, *second = new Node;
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};
    create(A, 9, first);
    create(A, 5, second);
    Display(first);
    Display(second);

    concat(first, second);
    Display(first);

    return 0;
}
