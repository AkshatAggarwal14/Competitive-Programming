#include <iostream>
using namespace std;

template <class T>
class Node {
   public:
    T data;
    Node *next;
};

template <class T>
class LL {
   private:
    Node<T> *first, *last;

   public:
    // --Constructors--

    LL() {
        first = nullptr;
        last = nullptr;
    }
    LL(T A[], int n);

    // --Destructor--
    ~LL();

    // --Prototypes--

    //Function to display contents of LL
    void Display();
    //Function which returns the length of LL
    int Length();
    //Function to insert an element at the end of linked list
    void Append(T x);
    //Function to concatenate argument LL at end of this LL
    // void Concat(Node<T> *node);
    //Function which returns head
    Node<T> *getHead() { return first; }
};

template <class T>
LL<T>::LL(T A[], int n) {
    Node<T> *t;           //last will be used to enter a new node at the ending
    first = new Node<T>;  //memory of size of structure is allocated, typecasted to type of struct
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = nullptr;  //no next node yet
        last->next = t;     // last node should point on t
        last = t;           // last becomes t, and t will be used for next node
    }

    last->next = nullptr;
}

template <class T>
LL<T>::~LL() {
    Node<T> *p = first;
    while (first) {
        first = first->next;
        delete p;  //deleting all nodes
        p = first;
    }
}

template <class T>
void LL<T>::Display() {
    Node<T> *p = first;  //first is already in class

    while (p) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << '\n';
}

template <class T>
int LL<T>::Length() {
    Node<T> *p = first;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
void LL<T>::Append(T x) {
    Node<T> *t = new Node<T>;
    t->data = x;
    t->next = nullptr;

    if (first == nullptr)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

template <class T>
void concat(Node<T> *first, Node<T> *second) {  //concats second to first
    Node<T> *p = first;                         //* extra pointer needed and O(n) time
    while (p->next) {                           //takes us to last node of first1
        p = p->next;
    }
    p->next = second;
    second = nullptr;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    LL<int> l1(A, 5), l2;
    l1.Display();
    l2.Append(6);
    l2.Append(10);
    l2.Append(100);
    l2.Display();
    // Concat(l1.first, l2.first);

    l1.Display();
    return 0;
}