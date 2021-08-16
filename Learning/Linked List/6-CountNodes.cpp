#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;  //next is a pointer of type struct as it will point to a struct
} *first = NULL;        // a global pointer, thus can be passed as parameter or directly accessed

//todo: create a linked list from an array and number of elements
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

//O(n) time complexity , O(1) space as constant space taken by p and cnt
int count(struct Node *p) {
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

//O(n) time complexity , O(n) space - costly
int Rcount(struct Node *p) {
    if (p == NULL)
        return 0;
    return Rcount(p->next) + 1;  //uses a stack as recursion

    //! +1 will be done afterwords, after we return Rcount() as 1 is added to result of the function thus 1+Rcount(p->next) will also add at the time of returning
    // for null 0 is returned
    // for pointer before null 0+1
    // then 1+2.. THUS addition is being done at returning time
}

/**
 * if(p!=NULL)
 *      return Rcount(p->next)+1;
 * return 0;
*/

/**
 *todo: Another implementation
int count(struct Node *p)
{
    int cnt = 0;
    if (p)
    {
        cnt=count(p->next);
        return cnt+1;
    }
    return cnt;
}
*/
int main() {
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    Display(first);

    cout << "Number of nodes: " << count(first);
    cout << "\nNumber of nodes Recursively: " << Rcount(first);
    return 0;
}
