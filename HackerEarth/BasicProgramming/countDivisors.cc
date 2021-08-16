//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, r, k, ctr = 0;
    cin >> l >> r >> k;
    rep(i, l, r + 1)
    {
        if (i % k == 0)
            ctr++;
    }
    cout << ctr;
    return 0;
}