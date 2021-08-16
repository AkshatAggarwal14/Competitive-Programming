// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Returns the total sum of
// occurrences of all vowels
ll vowel_calc(string s)
{
    ll n = s.length();
    vector<ll> arr;

    for (ll i = 0; i < n; i++)
    {

        if (i == 0)
            // No. of occurrences of 0th character
            // in all the substrings
            arr.push_back(n);

        else
            // No. of occurrences of the ith character
            // in all the substrings
            arr.push_back((n - i) + arr[i - 1] - i);
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++)

        // Check if ith character is a vowel
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            sum += arr[i];

    // Return the total sum
    // of occurrences of vowels
    return sum;
}

// Driver code
int main()
{
    ll t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        cout << vowel_calc(s) << endl;
    }
    return 0;
}