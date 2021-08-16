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

void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

int Add(Node *p) {  //O(n) space and time
    int sum = 0;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int R_Add(Node *p) {
    if (!p) return 0;
    return R_Add(p->next) + p->data;
}

int main() {
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    Display(first);
    cout << "Sum is: " << Add(first);
    cout << "\nUsing Recursion Sum is: " << R_Add(first);
    return 0;
}
