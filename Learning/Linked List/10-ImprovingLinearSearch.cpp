/*
How to make linear search better:
! Transposition- if we have to find key, we can change i-1 with i so key can be found earlier next time
* Move to Head- found key can be moved to head to reduce time if found again
*/

/*
? to do this we must modify previous node too thus we need a tail ptr
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

Node *Better_Search(Node *p, int key) {
    Node *q = nullptr;  //prev node
    while (p) {
        if (key == p->data) {  //when key found
            // now q's next should point on p's next
            q->next = p->next;  //this removes found node from linked list
            p->next = first;    //point p where first points
            first = p;          //makes p first

            return p;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

int main() {
    int A[] = {3, 5, 7, 10, 15, 3847, 2, -3, -5};

    create(A, 9);
    Display(first);
    Node *temp = Better_Search(first, 2);
    temp = Better_Search(first, 15);
    if (temp)
        cout << "Key is found " << temp->data;
    else
        cout << "Not found";
    cout << '\n';
    Display(first);  //thus 2 became first element

    return 0;
}
