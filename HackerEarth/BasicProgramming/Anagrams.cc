//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

const ll CHARS = 26;

ll removeToMakeAnagram(string str1, string str2)
{
    ll count1[CHARS] = {0}, count2[CHARS] = {0};
    for (ll i = 0; str1[i] != '\0'; i++)
        count1[str1[i] - 'a']++;
    for (ll i = 0; str2[i] != '\0'; i++)
        count2[str2[i] - 'a']++;
    ll ans = 0;
    for (ll i = 0; i < 26; i++)
        ans += abs(count1[i] - count2[i]);
    return ans;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << removeToMakeAnagram(s1, s2) << "\n";
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