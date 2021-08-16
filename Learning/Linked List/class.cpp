

#include <iostream>
using namespace std;

class LL {
   public:
    struct Node {
        int data;
        struct Node *next;
    };
    Node *first = NULL;
    friend void Display(LL);
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

    Node *merge(Node *second) {
        Node *third = nullptr;
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

        return third;
    }
};

void Display(LL t) {
    LL::Node *p = t.first;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

int main() {
    LL t1, t2;
    int A[] = {3, 5, 7, 10}, B[] = {1, 4, 6, 10};
    t1.create(A, 4);
    t2.create(B, 4);
    Display(t1);
    Display(t2);

    // Display(t1.merge(t2.first));
    // t1.Display();

    return 0;
}
