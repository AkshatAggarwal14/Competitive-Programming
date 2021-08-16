//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ans, steps = 0;
    cin >> n;
    ll arr[n], ctr[5] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        ctr[arr[i]]++;
    }
    sort(arr, arr + n, greater<ll>());
    //! IF NO 1 or 2 in input
    if (ctr[1] == 0 && ctr[2] == 0)
    {
        cout << "0\n";
        return 0;
    }
    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << "\n";
    //! To reduce 1s to 2
    ll p = ctr[1];
    while (p > 1)
    {
        ctr[2]++;
        p -= 2;
        ctr[1] = p;
        steps++;
    }
    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << "\n";
    //! To reduce 2s to 4
    ll q = ctr[2];
    while (q > 1)
    {
        ctr[4]++;
        q -= 2;
        ctr[2] = q;
        steps++;
    }
    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << "\n";
    //! to reduce all 4 and 2 to 3
    ll x = ctr[2], y = ctr[4];
    while (x > 0 && y > 0)
    {
        y--;
        x--;
        ctr[2] = x;
        ctr[4] = y;
        ctr[3] += 2;
        steps++;
    }

    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << endl;
    //! To reduce all 1 and 2 to 3
    ll a = ctr[1], b = ctr[2];
    while (a > 0 && b > 0)
    {
        a--;
        b--;
        ctr[3]++;
        ctr[1] = a;
        ctr[2] = b;
        steps++;
    }
    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << "\n";
    //! to reduce 1 and 3 to 4
    ll r = ctr[1], s = ctr[3];
    while (r > 0 && s > 0)
    {
        r--;
        s--;
        ctr[4]++;
        ctr[1] = r;
        ctr[3] = s;
        steps++;
    }
    // for (ll i = 0; i < 5; i++)
    //     cout << ctr[i] << " ";
    // cout << "\n";

    cout << steps << "\n";
    return 0;
}