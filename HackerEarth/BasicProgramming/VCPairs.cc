//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

bool vowelorConsonant(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return 1; //if vowel
    else
        return 0; //if consonant
}

void solve()
{
    ll n, ans = 0;
    cin >> n;
    char str[n];
    cin >> str;
    for (ll i = 1; i < n; i++)
    {
        if (vowelorConsonant(str[i]) == 1 && vowelorConsonant(str[i - 1]) == 0)
            ans++;
    }
    cout << ans << "\n";
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