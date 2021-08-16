//? TWO POINTER METHOD
//* Now let’s see how the two-pointer technique works. We take two pointers, one representing the first element and other representing the last element of the array, and then we add the values kept at both the pointers. If their sum is smaller than X then we shift the left pointer to right or if their sum is greater than X then we shift the right pointer to left, in order to get closer to the sum. We keep moving the pointers until we get the sum as X
//todo: O(n)
#include <iostream>
using namespace std;

// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
bool isPairSum(int A[], int N, int X) {
    // represents first pointer
    int i = 0;

    // represents second pointer
    int j = N - 1;

    while (i < j) {
        // If we find a pair
        if (A[i] + A[j] == X)
            return true;

        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;

        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return false;
}

// Driver code
int main() {
    // array declaration
    int arr[] = {3, 5, 9, 2, 8, 10, 11};

    // value to search
    int val = 17;

    // size of the array
    int arrSize = *(&arr + 1) - arr;

    // Function call
    cout << isPairSum(arr, arrSize, val);

    return 0;
}
