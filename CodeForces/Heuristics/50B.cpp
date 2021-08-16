#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll maxprime(ll n)
{
    ll maxPrime = -1;
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }

    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

void solve()
{
    ll N;
    cin >> N;
    cout << maxprime(N) << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}