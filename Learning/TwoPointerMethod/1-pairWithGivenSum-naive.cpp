// Naive solution to find if there is a
// pair in A[0..N-1] with given sum.
//todo: O(n*n)
#include <bits/stdc++.h>
using namespace std;

bool isPairSum(int A[], int N, int X) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // as equal i and j means same element
            if (i == j)
                continue;

            // pair exists
            if (A[i] + A[j] == X)
                return true;

            // as the array is sorted
            if (A[i] + A[j] > X)
                break;
        }
    }

    // No pair found with given sum.
    return false;
}

// Driver code
int main() {
    int arr[] = {3, 5, 9, 2, 8, 10, 11};
    int val = 17;
    //! https://stackoverflow.com/questions/61237796/how-does-arr-1-arr-give-the-length-in-elements-of-array-arr
    // int arrSize = *(&arr + 1) - arr;
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + arrSize);  //* Sort the array
    // Function call
    cout << isPairSum(arr, arrSize, val);

    return 0;
}

/*
Given the following facts:
*When you increment/decrement a pointer by an integral value X, the value of the pointer is increased/decreased by X times the number of bytes of the type the pointer is pointing at.

*When you subtract 2 pointers of the same type, the result is the difference between their held addresses, divided by the number of bytes of the type being pointed at.

*When you refer to an array by its name alone, it decays into a pointer to the array's 1st element.
?The type of your arr variable is int[5], ie an array of 5 ints. &arr returns an int[5]* pointer to arr (technically, it is actually written like int(*)[5], but lets not worry about that here, for simplicity). Lets call this pointer temp below.

?Then, the + 1 increments the value of temp by 1 int[5] element. In other words, the address stored in temp is increased by 1 * sizeof(int[5]), or 1 * (sizeof(int) * 5), number of bytes. This effectively gives you an int[5]* pointer to the end of arr (ie, to &arr[5]). No int[5] element physically exists at that memory address, but it is legal to create a pointer to it, for purposes of pointer arithmetic.

?Dereferencing temp gives you a reference to an int[5] at the end of arr. That reference decays into an int* pointer when passed to operator-.
In - arr, the reference to arr decays into an int* pointer to arr[0] when passed to operator-.

Thus, given this code:
int len = *(&arr + 1) - arr;
*/