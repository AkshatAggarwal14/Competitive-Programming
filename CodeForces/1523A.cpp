//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repeq(i, a, b) for (ll i = a; i <= b; i++)
#define repn(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    string s, s1, prev;
    cin >> s;
    s1 = s;
    prev = s;

    while (m--)
    {
        if (s[0] == '0' && s[1] == '1')
            s1[0] = '1';
        for (ll i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' && s[i + 1] == '1')
                {
                    continue;
                }
                if ((s[i - 1] == '1' && s[i + 2] == '1'))
                {
                    s1[i] = '1';
                    s1[i + 1] = '1';
                    i++;
                }
                else if ((s[i - 1] == '1' || s[i + 1] == '1'))
                {
                    s1[i] = '1';
                    i++;
                }
            }
            // cout << s1 << " i:" << i << "\n";
        }
        if (s[n - 2] == '1' && s[n - 1] == '0')
            s1[n - 1] = '1';
        s = s1;
        // cout << s1 << " " << m << "\n";
        if (prev == s) //! This is done to reduce runtime as if the string repeats then we can just break this loop and give the answer
            break;
        prev = s;
    }
    // cout << s1 << " Hello\n\n";
    cout << s1 << "\n";
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