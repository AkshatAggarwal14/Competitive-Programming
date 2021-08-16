#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;
typedef char ch[300000];

bool checkPalindrome(char str1[])
{
    ch str2;
    ll len = strlen(str1) - 1, flag = 0;
    for (ll i = len, j = 0; i >= 0; i--, j++)
        str2[j] = str1[i];
    if (str1 == str2)
        flag = 1;
    if (flag == 1)
        return 1;
    return 0;
}

void solve()
{
    ch s;
    cin >> s;
    ll n = strlen(s);
    if (checkPalindrome(s) == 1)
    {
        cout << "YES";
        if (checkPalindrome('a' + s) == 1)
            cout << 'a' + s;
        else
            cout << s + 'a';
    }
    else
        cout << "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}