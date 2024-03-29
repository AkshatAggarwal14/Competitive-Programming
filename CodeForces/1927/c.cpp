#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, n) for (i = 0; i < n; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define m_p make_pair
const ll mod = 1e9 + 7;
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n), b(m);
    ll i;
    fo(i, n)
            cin >>
        arr[i];
    fo(i, m)
            cin >>
        b[i];
    map<ll, ll> mpp1, mpp2;
    fo(i, n)
        mpp1[arr[i]]++;
    fo(i, m)
        mpp2[b[i]]++;
    ll c1 = 0, c2 = 0, c3 = 0;
    for (i = 1; i <= k; i++) {
        if (mpp1.find(i) == mpp1.end() && mpp2.find(i) == mpp2.end()) {
            cout << "NO"
                 << "\n";
            return;
        } else if (mpp1.find(i) != mpp1.end() && mpp2.find(i) != mpp2.end()) {
            c3++;
        } else if (mpp1.find(i) != mpp1.end()) {
            c1++;
        } else {
            c2++;
        }
    }
    if (c1 <= k / 2 && c2 <= k / 2)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
}
//---------------------------------------------------------------------------------------------
int main() {
    // BINARY SEARCH ON ANS
    // DISJOINT SET UNION
    // INVERSE MODULO
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    // t=1;
    while (t--) {
        solve();
    }
}
//---------------------------------------------------------------------------------------------```