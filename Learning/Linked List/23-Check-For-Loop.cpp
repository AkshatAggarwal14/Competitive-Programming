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

/*
    if last node is linked to some other node, then linked list is Looped, otherwise linear
    ? if we scan and encounter a null its linear
    Todo: to check if looped (as we never have null, so transversing is infinite loop)
    ? 1. we can store addresses and if encounter again then loop
    ? 2. if unique elements store elements
    ? 3. Using two pointers which start from first node
        - p will move by one step and q will move by 2 steps
        - if linear these never meet again 
        - but in loop these will always meet once in two rounds
*/

bool isLoop(Node *head) {  // O(n)
    Node *p, *q;
    p = q = head;  // p moves once, q moves twice
    while (p && q) {
        p = p->next;
        q = q->next;
        q = (q) ? q->next : nullptr;  //dont go to next if already null
        if (p == q) return true;
    }
    return false;
}

int main() {
    Node *t1, *t2;
    int A[] = {3, 5, 7, 10, 20};
    create(A, 5);
    Display(first);

    int n;
    cin >> n;  //if n is not zero we make a loop and then check
    if (n) {
        t1 = first->next->next;
        t2 = first->next->next->next->next;
        t2->next = t1;  //makes loop
    }

    if (isLoop(first))
        cout << "Loop\n";
    else
        cout << "Linear\n";

    return 0;
}
