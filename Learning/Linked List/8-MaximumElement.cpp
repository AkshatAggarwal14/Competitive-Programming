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

int Max(Node *p) {
    int mx = INT_MIN;
    while (p) {
        mx = max(mx, p->data);
        p = p->next;
    }
    return mx;
}

//! JUST TWO LINES
int R_Max(Node *p) {
    if (!p) return INT_MIN;  //for last return min
    // int x = R_Max(p->next);
    // return x > p->data ? x : p->data;
    return max(R_Max(p->next), p->data);
}

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};

    create(A, 9);
    Display(first);
    cout << "Max element is: " << Max(first);
    cout << "\nMax element is: (Using Recursion) " << R_Max(first);  //similar for minimum element

    return 0;
}
