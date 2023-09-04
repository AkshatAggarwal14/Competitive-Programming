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
    vector<pair<ll, ll>> a(n);
    map<ll, vector<ll>> mp;
    for (auto &x : a) {
        cin >> x.first >> x.second;
        mp[x.first].push_back(x.second);
    }

    for (auto &[x, y] : mp) {
        sort(y.rbegin(), y.rend());
    }

    ll ans = 0;
    vector<ll> mxs;
    for (auto &[x, y] : mp) {
        mxs.push_back(y.front());
    }
    sort(mxs.rbegin(), mxs.rend());
    if (mxs.size() >= 2) {
        ans = max(ans, mxs[0] + mxs[1]);
    }

    for (auto &[x, y] : mp) {
        if (y.size() >= 2) {
            ans = max(ans, y[0] + y[1] / 2);
        }
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
