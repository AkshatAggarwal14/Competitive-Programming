//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n], largest = 0, s = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        largest = max(a[i], largest);
    }
    if ((s - largest) > largest)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}