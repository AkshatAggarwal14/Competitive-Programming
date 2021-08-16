#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;  //next is a pointer of type struct as it will point to a struct
};

int main() {
    return 0;
}

/*
Never touch the "first" pointer instead take another temporary pointer
struct node *p = first; //Thus now we are on the first node 
p=p->next; //to move to the next node
thus to do this repeatedly we use a while loop, WHILE loop because we dont know how many nodes 
* while (p != NULL) {
*      cout << p->data << " "; //to display the data
*      p = p->next;
*  }
*/

/*
? void display(struct node *p)
? {
?    while (p != NULL) 
?    {
?        cout << p->data << " ";
?        p = p->next;
?    }
? }
 */