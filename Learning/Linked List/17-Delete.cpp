#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = nullptr, *last = nullptr;

void Display(Node *p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    return;
}

void InsertLast(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;

    if (first == nullptr)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

int count(struct Node *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/*
    While deleting a node, there are two cases:
    1. Deleting the first node, This is a special case as first pointer changes
    2. Deleting a node at a given position, just remove a link in between
*/

//! deallocate memory when deleting a node
//new is used to create a new node in heap, delete is used to delete from heap

int deleteNode(int pos) {
    Node *p = first, *q = nullptr;
    int x = -1;

    if (pos < 1 || pos > count(p)) return -1;
    if (pos == 1) {  //? O(1) and extra pointer is needed
        first = first->next;
        x = p->data;  //data taken out
        free(p);
        return x;
    } else {  //? O(n)
        /*
        the node previous to the node to be deleted needs to point to the next node
        So two pointers are needed, one on pos, and one on pos-1
        */
        for (int i = 0; i < pos - 1 && p; ++i) {  //p is checked if null which it becomes at end
            q = p;
            p = p->next;
        }
        if (p) {  //p can become null
            q->next = p->next;
            x = p->data;
            free(p);
        }
        return x;
    }
}

int main() {
    InsertLast(3);
    InsertLast(7);
    InsertLast(9);
    InsertLast(15);
    InsertLast(20);
    Display(first);

    cout << "Deleted element is: " << deleteNode(1) << '\n';
    Display(first);

    cout << "Deleted element is: " << deleteNode(4) << '\n';
    Display(first);

    cout << "Deleted element is: " << deleteNode(2) << '\n';
    Display(first);

    cout << "Deleted element is: " << deleteNode(1) << '\n';
    Display(first);

    cout << "Deleted element is: " << deleteNode(1) << '\n';
    cout << "Deleted element is: " << deleteNode(1) << '\n';

    return 0;
}
