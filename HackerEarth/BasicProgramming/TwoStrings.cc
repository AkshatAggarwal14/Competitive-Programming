//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length())
    {
        cout << "NO\n";
        return;
    }
    ll count1[26] = {0}, count2[26] = {0};
    for (ll i = 0; i < s1.length(); i++)
        count1[s1[i] - 'a']++;
    for (ll i = 0; i < s2.length(); i++)
        count2[s2[i] - 'a']++;
    ll flag = 0;
    for (ll i = 0; i < 26; i++)
        if (count1[i] != count2[i])
        {
            flag = 1;
            break;
        }
    if (flag == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
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