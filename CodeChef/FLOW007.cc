//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, rev = 0;
    cin >> n;
    while (n != 0)
    {
        int remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    cout << rev << "\n";
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