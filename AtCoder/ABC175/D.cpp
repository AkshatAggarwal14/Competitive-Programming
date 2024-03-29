#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 6e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

ll maxCircular(vector<ll> &v, ll k) {
    ll n = ll(v.size());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    v.insert(v.end(), v.begin(), v.end());

    ll len = ll(v.size());
    vector<ll> pref(len + 1);
    pref[0] = 0;
    for (ll i = 1; i <= len; ++i) {
        pref[i] = pref[i - 1] + v[i - 1];
    }

    ll ans = LLONG_MIN;
    for (ll lastLen = 1; lastLen <= min(k, n); ++lastLen) {
        ll leftLen = k - lastLen;
        ll fullTimes = leftLen / n;

        ll mx = LLONG_MIN;
        // find max subarray sum of length lastLen
        for (ll start = 0; lastLen + start <= len; ++start) {
            ll tsum = pref[lastLen + start] - pref[start];
            mx = max(mx, tsum);
        }
        ans = max(ans, fullTimes * max(sum, 0LL) + mx);
    }

    return ans;
}

void test() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    for (auto &x : p) cin >> x, --x;
    for (auto &x : c) cin >> x;

    vector<bool> vis(n, false);
    vector<vector<ll>> cycles;
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<ll> cycle;
        while (!vis[i]) {
            vis[i] = true;
            i = p[i];
            cycle.push_back(c[i]);
        }
        cycles.push_back(cycle);
    }

    ll ans = LLONG_MIN;
    for (auto &cycle : cycles) {
        ans = max(ans, maxCircular(cycle, k));
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
