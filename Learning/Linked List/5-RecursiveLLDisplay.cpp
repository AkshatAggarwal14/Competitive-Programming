//RDisplay means Recursive Display
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;  //next is a pointer of type struct as it will point to a struct
} *first = NULL;        // a global pointer, thus can be passed as parameter or directly accessed

//todo: create a linked list from an array and number of elements
void create(int A[], int n) {
    int i;
    struct Node *t, *last;                               //last will be used to enter a new node at the ending
    first = (struct Node *)malloc(sizeof(struct Node));  //memory of size of structure is allocated, typecasted to type of struct
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;  //no next node yet
        last->next = t;  // last node should point on t
        last = t;        // last becomes t, and t will be used for next node
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

//todo: print a linked list taking in the first pointer
// O(n) space and time, also number of calls for entire linked list will be n+1 and stack size will be n+1
void RDisplay(struct Node *p) {
    if (p != NULL)  //when not NULL, it is print and then next node is printed recursively
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
    return;
}

//todo: Display a linked list in reverse order using Recursion
void RDisplayReverse(struct Node *p)  //prints while returning
{
    if (p != NULL) {
        RDisplayReverse(p->next);  //goes until end in recursion and then prints in reverse, by deleting its activation record at each step;
        //if Display() used here then 3 5 7 10 15 ----- 5 7 10 15 3
        cout << p->data << " ";
    }
    return;
}

int main() {
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    RDisplay(first);
    cout << "\n";
    RDisplayReverse(first);

    return 0;
}
