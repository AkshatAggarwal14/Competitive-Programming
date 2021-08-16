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

int count(Node *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*
    ? There are two methods to reverse a linked list:
    1. Reversing the elements (The node addresses will remain same && data in node will change)
    ! --> copy elements to array, reverse it, copy arrays element to list
    2. Reversing the links 
        2.1 (The addresses will remain same but the order of nodes will change as links change)
        2.2 Using recursion
*/

//* m1
void Reverse1(Node *p) {  //Requires extra space, array of equal size, and O(n) time
    int i = 0;
    int *arr = new int[count(p)];
    while (p) {
        arr[i++] = p->data;
        p = p->next;
    }
    i--;
    p = first;
    while (p) {
        p->data = arr[i--];
        p = p->next;
    }
}

//* m2
void Reverse2(Node *p) {
    //todo: using sliding pointers (3 pointers moving together)
    Node *q = nullptr, *r = nullptr;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;  // <-- this reverses the links
    }
    first = q;  //at the end
}

void R_Reverse2(Node *q, Node *p) {
    if (p) {
        R_Reverse2(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};
    create(A, 9);
    Display(first);

    Reverse1(first);
    Display(first);

    Reverse2(first);  //! preferred as if there is a lot of data in the node then it is hard to move the data between nodes
    Display(first);

    R_Reverse2(nullptr, first);
    Display(first);

    return 0;
}
