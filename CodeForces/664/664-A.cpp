//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    while (a > 0 && b > 0 && c > 0)
    {
        a--;
        b--;
        c--;
        d += 3;
    }
    bool A = (a % 2 == 0);
    bool B = (b % 2 == 0);
    bool C = (c % 2 == 0);
    bool D = (d % 2 == 0);
    if (A && B && C && D)
        cout << "Yes\n";
    else if (!A && B && C && D)
        cout << "Yes\n";
    else if (A && !B && C && D)
        cout << "Yes\n";
    else if (A && B && !C && D)
        cout << "Yes\n";
    else if (A && B && C && !D)
        cout << "Yes\n";
    else
        cout << "No\n";
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