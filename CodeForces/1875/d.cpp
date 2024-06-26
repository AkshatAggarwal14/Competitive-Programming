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
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto &x : a)
        cin >> x, ++cnt[x];

    ll mex = 0;
    while (mex < n and cnt.count(mex))
        ++mex;

    if (cnt[0] <= 1) {
        return void(cout << "0\n");
    }

    // dp[i] = min cost to break mex chain from [i..mex-1]
    vector<ll> dp(mex + 1, INF);
    dp[mex] = 0;
    for (ll i = mex - 1; i >= 0; i--) {
        for (ll j = i + 1; j <= mex; j++) {
            // mex is j for (cnt[i] - 1) times, then mex becomes i after last removal
            dp[i] = min(dp[i], (cnt[i] - 1) * j + i + dp[j]);
        }
    }
    cout << dp[0] << '\n';
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
