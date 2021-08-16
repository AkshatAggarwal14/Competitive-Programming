//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    char s[n];
    cin >> s;
    for (ll i = 0; s[i] != '\0'; i++)
    {
        ll d[12];
        char c[12] = {'C', 'G', 'I', 'O', 'S', 'Y', 'a', 'e', 'g', 'k', 'm', 'q'};
        d[0] = abs(s[i] - 'C');
        d[1] = abs(s[i] - 'G');
        d[2] = abs(s[i] - 'I');
        d[3] = abs(s[i] - 'O');
        d[4] = abs(s[i] - 'S');
        d[5] = abs(s[i] - 'Y');
        d[6] = abs(s[i] - 'a');
        d[7] = abs(s[i] - 'e');
        d[8] = abs(s[i] - 'g');
        d[9] = abs(s[i] - 'k');
        d[10] = abs(s[i] - 'm');
        d[11] = abs(s[i] - 'q');
        ll minindex = distance(d, find(d, d + 12, *min_element(d, d + 12)));
        s[i] = c[minindex];
    }
    cout << s << "\n";
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