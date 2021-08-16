/**
 * The first pointer is called "First" or "Head"
*/

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
*when q=p;
? now q points to the same element that p is pointing to

      ptr p        ptr q
address: 200        200
        |        /             
        |      /                
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+
    ! 200           210

*when q=p->next;
? Let q point on next node of p

      ptr p        ptr q
address: 200        210 
        |             |             
        |             |             
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+
    ! 200           210
    
*when p=p->next;
? Let p point on next node of p (its own next node)
P has moved to the next node
! Hence p->=next or p=p->next; is a very useful statement

         ptr p       
     address: 210 
               \                         
                \                        
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+
    ! 200           210
    
* struct node *p=NULL; 
this makes the pointer NULL; struct node *p=0; also possible
when pointer is not pointing to any node it is 0 or false
when it is pointing it is not zero thus true

* if(p==NULL) <- this is when pointer is not pointing to any node
*or if(p==0)
*ot if(!p) <- will be true when p is false i.e. when it is not pointing anywhere

! it will point to some node when,
*if(p!=NULL)
*if(p!=0)
*if(p)

! if(p->next==NULL)
as p is not pointing anywhere thus p is last node in linked list

*if(p->next!=NULL) means there is some node after the node that p is pointing to
    */