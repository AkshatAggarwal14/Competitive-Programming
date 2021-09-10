/*
    -> It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 
    1. Always pick first element as pivot.
    ? 2. Always pick last element as pivot (implemented below)
    3. Pick a random element as pivot.
    4. Pick median as pivot.

    * The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
*/

#include <iostream>
// using namespace std;

int partition(int arr[], int start, int end);

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // P is partitioning index
        //* arr[P] is now at right place

        int P = partition(arr, start, end);
        for (int i = 0; i < 10; ++i) std::cout << arr[i] << " ";
        std::cout << '\n';
        quickSort(arr, start, P - 1);  // before P
        for (int i = 0; i < 10; ++i) std::cout << arr[i] << " ";
        std::cout << '\n';
        quickSort(arr, P + 1, end);  // after P
    }
}

//* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

int partition(int arr[], int start, int end) {
    int pivot = arr[end];  // pivot (Element to be placed at right position)
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (start - 1);
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return (i + 1);
}

int main() {
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(A, 0, 9);
    for (int i = 0; i < 10; ++i) std::cout << A[i] << " ";
    std::cout << '\n';
    return 0;
}