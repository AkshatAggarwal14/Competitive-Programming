//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll D, d, A, B, C;
    cin >> D >> d >> A >> B >> C;
    ll x = d * D;
    if ((D >= 1 && D <= 10) && (d >= 1 && d <= 5) && (A >= 1 && A <= 1e5) && (B >= 1 && B <= 1e5) && (C >= 1 && C <= 1e5))
    {
        if (x >= 42)
            cout << C << "\n";
        else if (x >= 21)
            cout << B << "\n";
        else if (x >= 10)
            cout << A << "\n";
        else
            cout << "0\n";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t >= 1 && t <= 50)
        while (t--)
            solve();
    return 0;
}