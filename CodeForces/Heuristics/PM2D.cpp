/*
    sum of variables >= n(n-1)/2 according to test cases
    ith stack to (i+1)
    0 1 2 3<== index
    3 1 2 0
    2 2 2 0
    1 3 2 0
    1 2 3 0
    0 3 3 0
    0 1 5 0
    0 1 2 3
    <-- thus min sum for strictly increasing is n(n-1)/2
    */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;
    int flag = 1; //indicator
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < ((i * (i + 1)) / 2))
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}