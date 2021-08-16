//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll count[26] = {0};
    for (ll i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }
    ll sum = 0;
    for (ll i = 0; i < 26; i++)
    {
        sum += (i + 1) * count[i];
    }
    cout << sum;
    return 0;
}