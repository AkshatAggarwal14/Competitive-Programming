

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
void create2(int A[], int n) {
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
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

/*
    Here we have two sorted linked lists and we need to merge them into one sorted list
    ? merging array needs third array but linked list doesnt

    The first of resulting linked list is the first which is smaller, we push the other linked list into this one
    third pointer initally points to smaller first, i.e. first of answer;
    then we move first to next and second to next and compare, add to third and repeat
*/

void merge(Node *first, Node *second) {  //* O(m+n)

    Node *last = new Node;  //these are last and first node of result
    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = nullptr;
    } else {
        third = last = second;
        second = second->next;
        last->next = nullptr;
    }

    while (first != nullptr && second != nullptr) {  //until one of the lists become zero
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
}

int main() {
    int A[] = {3, 5, 7, 10}, B[] = {1, 4, 6, 10};
    create(A, 4);
    create2(B, 4);
    Display(first);
    Display(second);

    merge(first, second);
    Display(third);
    // Display(first); //as links are modified they start from the element but contains all other
    // Display(second);

    return 0;
}
