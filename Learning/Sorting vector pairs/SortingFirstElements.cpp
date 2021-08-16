// C++ program to demonstrate sorting in
// vector of pair according to 1st element
// of pair
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declaring vector of pairs
    vector<pair<int, int>> vect;

    // Initializing 1st and 2nd element of
    // pairs with array values
    int arr[] = {10, 20, 5, 40};
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(arr[i], arr1[i]));

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n";
    for (int i = 0; i < n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    // Using simple sort() function to sort
    sort(vect.begin(), vect.end());

    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n";
    for (int i = 0; i < n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    return 0;
}