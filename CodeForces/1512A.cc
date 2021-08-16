//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    repn(i, n)
    {
        cin >> arr[i];
    }
    if (arr[0] != arr[1] && arr[1] == arr[2])
    {
        cout << "1\n";
    }
    else
    {
        ll temp = arr[0];
        rep(i, 1, n)
        {
            if (arr[i] != arr[0])
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}