//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)
const int MAX_CHAR = 26;

// function to print string in sorted order
void sortString(string &str)
{
    // Hash array to keep count of characters.
    // Initially count of all charters is
    // initialized to zero.
    int charCount[MAX_CHAR] = {0};

    // Traverse string and increment
    // count of characters
    for (int i = 0; i < str.length(); i++)

        // 'a'-'a' will be 0, 'b'-'a' will be 1,
        // so for location of character in count
        // array we wil do str[i]-'a'.
        charCount[str[i] - 'a']++;

    // Traverse the hash array and print
    // characters
    for (int i = 0; i < MAX_CHAR; i++)
        for (int j = 0; j < charCount[i]; j++)
            cout << (char)('a' + i);
    cout << "\n";
}

typedef long long ll;
//SORT STRING TO SOLVE
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // sort(s.begin(), s.end());
    // cout << s << "\n";
    // OR
    sortString(s);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}