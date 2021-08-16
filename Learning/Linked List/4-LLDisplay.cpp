#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;  //next is a pointer of type struct as it will point to a struct
} *first = NULL;        // a global pointer, thus can be passed as parameter or directly accessed

//todo: create a linked list from an array and number of elements
void create(int A[], int n) {
    Node *t, *last;                                      //last will be used to enter a new node at the ending
    first = (struct Node *)malloc(sizeof(struct Node));  //memory of size of structure is allocated, typecasted to type of struct
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;  //no next node yet
        last->next = t;  // last node should point on t
        last = t;        // last becomes t, and t will be used for next node
    }
}

//todo: print a linked list taking in the first pointer
void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << ", ";
        p = p->next;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    Display(first);

    return 0;
}
