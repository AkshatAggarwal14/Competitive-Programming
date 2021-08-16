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

/*
    Here we have two sorted linked lists and we need to merge them into one sorted list
    ? merging array needs third array but linked list doesnt

    The first of resulting linked list is the first which is smaller, we push the other linked list into this one
*/

Node *merged(Node *first, Node *second) {  //* O(m+n)
    /*
        third pointer initally points to smaller first, i.e. first of answer;
        then we move first1 to next and first2 to next and compare, add to third and repeat
    */

    Node *last = new Node, *third = new Node;  //these are last and first node of result
    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = nullptr;
    } else {
        third = last = second;
        second = second->next;
        last->next = nullptr;
    }

    while (first != nullptr && second != nullptr) {
        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = nullptr;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }
    if (first != nullptr)
        last->next = first;
    else
        last->next = second;
    return third;
}

int main() {
    Node *first = new Node, *second = new Node;
    int A1[] = {2, 8, 10, 15}, A2[] = {4, 7, 12, 14};
    create(A1, 4, first);
    create(A2, 4, second);
    Display(first);
    Display(second);

    Node *result = merged(first, second);
    Display(result);

    return 0;
}
