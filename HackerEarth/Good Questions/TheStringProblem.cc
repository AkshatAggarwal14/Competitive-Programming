//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    string s, test1 = "AEIOU", test2 = "aeiou";
    cin >> s;

    int a = 0, b = 0;
    for (int y = 0; y < 5; y++)
        for (int i = 0; i < s.length(); i++)
            if (test1[y] == s[i])
            {
                a++;
                break;
            }
    for (int y = 0; y < 5; y++)
        for (int i = 0; i < s.length(); i++)
            if (test2[y] == s[i])
            {
                b++;
                break;
            }

    if (a == 5 || b == 5)
        cout << "lovely string\n";
    else
        cout << "ugly string\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}