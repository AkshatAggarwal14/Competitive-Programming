/*
! Search in linked list
* Linear Search
* Binary Search (cant be used as we cant reach the middle element in linear time)
*/

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

Node *Search(Node *p, int key) {
    while (p) {
        if (key == p->data) return p;
        p = p->next;
    }
    return nullptr;
}

//! check if present
// bool Search(Node *p, int key) {
//     while (p) {
//         if (key == p->data) return true;
//         p = p->next;
//     }
//     return false;
// }

Node *R_Search(Node *p, int key) {
    if (!p) return nullptr;
    if (key == p->data) return p;
    return R_Search(p->next, key);
}

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};

    create(A, 9);
    Display(first);

    Node *temp = R_Search(first, 12);
    if (temp)
        cout << "Key is found " << temp->data;
    else
        cout << "Not found";

    return 0;
}
