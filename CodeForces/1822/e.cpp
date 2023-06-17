#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> c1(26, 0), c2(26, 0);
    for (ll i = 0; i < n; ++i) ++c1[s[i] - 'a'];
    for (ll i = 0; i < n / 2; ++i)
        if (s[i] == s[n - 1 - i]) ++c2[s[i] - 'a'];

    ll sum = accumulate(c2.begin(), c2.end(), 0LL);
    ll mx = *max_element(c2.begin(), c2.end());

    ll mxFreq = *max_element(c1.begin(), c1.end());

    if (mxFreq > n / 2 || (n & 1)) {
        return void(cout << "-1\n");
    }
    if (mx > sum - mx) {
        cout << mx << '\n';
    } else {
        cout << (sum + 1) / 2 << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
