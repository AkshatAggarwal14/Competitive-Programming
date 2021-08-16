#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countRect(int a)
{
    ll ans = 0;
    if (a % 2 != 0) // if odd
    {
        for (int i = 1; i <= sqrt(a); i += 2)
        {
            int val1 = i;
            int val2 = a / val1;
            if ((val1 * val2) == a)
                ans++;
        }
    }
    else // if even
    {
        int val = sqrt(a);
        if (val * val == a)
            ans++;
        for (int i = 1; i <= sqrt(a); i++)
        {
            int val1 = i;
            int val2 = a / val1;
            if ((val1 * val2) == a && (val1 % 2 != 0 or val2 % 2 != 0))
                ans++;
        }
    }
    return ans;
}

void solve()
{
    int a;
    cin >> a;
    cout << countRect(a) << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}