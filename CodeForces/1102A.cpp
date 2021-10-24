//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n, sum;
    cin >> n;
    if (n % 4 == 0 || n % 4 == 3)
        cout << 0;
    else
        cout << 1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
    long long int n, sum;
    cin >> n;
    if (n % 4 == 0 || n % 4 == 3)
        cout << 0;
    else
        cout << 1;
    return 0;
}
*/