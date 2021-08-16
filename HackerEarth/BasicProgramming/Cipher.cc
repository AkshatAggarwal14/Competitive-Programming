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
    ll k;
    cin >> k;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = ((s[i] - 'A' + k) % 26) + 'A';
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = ((s[i] - 'a' + k) % 26) + 'a';
        if (s[i] >= '0' && s[i] <= '9')
            s[i] = ((s[i] - '0' + k) % 10) + '0';
    }
    cout << s;
    return 0;
}