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
    int n;
    cin >> n;
    vector<ll> a(n - 1);
    for (auto &x : a) cin >> x;

    vector<ll> d(n - 1);
    d[0] = a[0];
    for (int i = 1; i < n - 1; ++i) d[i] = a[i] - a[i - 1];

    vector<bool> vis(n + 1, false);
    vector<ll> extra;
    for (auto &val : d) {
        if (val >= 1 && val <= n && !vis[val]) {
            vis[val] = true;
        } else {
            extra.push_back(val);
        }
    }

    // we might not need to break and element, if the last term of prefix sum was removed
    if (extra.empty()) {
        // always exist as n - 1 elements were all in [1, n]
        cout << "YES\n";
        return;
    }
    if (int(extra.size()) > 1) {
        cout << "NO\n";
        return;
    }

    for (ll part = 1; part <= n; ++part) {
        if (!vis[part]) {
            ll left = extra[0] - part;
            if (left >= 1 && left <= n && !vis[left] && left != part) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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