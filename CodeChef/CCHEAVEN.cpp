//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long LNG;
void solve()
{
    LNG l, flag = 0;
    char s[l];
    cin >> l >> s;
    for (LNG i = 1; i <= l; i++)
    {
        LNG good = 0, bad = 0, j;
        for (j = 0; j < i; j++)
            if (s[j] == '1')
                good++;
        if (good >= (j / 2 + j % 2))
        {
            flag = 1;
            break;
        }
    }
    if (l >= 1 && l <= 1e5)
    {
        if (flag == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LNG t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}