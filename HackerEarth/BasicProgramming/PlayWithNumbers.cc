//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    ll L[q], R[q];
    rep(i, 0, q)
    {
        cin >> L[i] >> R[i];
        ll num = R[i] - L[i] + 1, sum = 0;
        for (ll j = L[i]; j <= R[i]; j++)
            sum += arr[j - 1]; //as indices of array
        cout << sum / num << "\n";
    }
    return 0;
}