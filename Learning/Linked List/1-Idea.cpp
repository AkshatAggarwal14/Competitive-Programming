#include <iostream>
using namespace std;

int main() {
    //! Arrays - fixed size
    // Arrays are like a bench
    int arr[5];
    int *p = new int[5];  //like chairs whoever needs can allocate one
    //! Similarly we can allocate the space for just one element and one pointer, which points to next element, this one element is a Node
    /**
     * Node will contain data as well as pointer to next Node, NULL when no 2nd element 
     * Like group of chairs and anyone can bring and take away chair, each element brings its own memory, THUS we can make linked list inside heap
     **/
    /* data has been assigned to the data part of the second
    block (block pointed by second). And next
    pointer of the second block points to the third
    block. So all three blocks are linked.
    
    head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+     */
}