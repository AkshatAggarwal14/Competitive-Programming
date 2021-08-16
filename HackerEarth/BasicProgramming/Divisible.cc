//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

ll firstDigit(ll n)
{
    int digits = (int)log10(n);
    n = (int)(n / pow(10, digits));
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    rep(i, 0, n)
    {
        ll t;
        cin >> t;
        if (i < n / 2)
            arr[i] = firstDigit(t);
        else
            arr[i] = t % 10;
    }
    ll s = 0, term = 1;
    rep(i, 0, n)
    {
        s += arr[i] * term;
        term *= -1;
    }
    if (s % 11 == 0)
        cout << "OUI";
    else
        cout << "NON";
    return 0;
}