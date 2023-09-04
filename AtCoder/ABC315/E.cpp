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
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; ++i) {
        ll c;
        cin >> c;
        for (ll j = 0; j < c; ++j) {
            ll x;
            cin >> x, --x;
            g[i].push_back(x);
        }
    }

    auto toposort = [&]() {
        vector<bool> visited(n, false);
        vector<ll> st;

        function<void(ll)> dfs = [&](ll node) {
            visited[node] = true;

            for (auto &child : g[node]) {
                if (!visited[child]) {
                    dfs(child);
                }
            }

            st.push_back(node);
        };

        dfs(0);

        return st;
    };

    auto pos = toposort();
    for (auto &x : pos) {
        if (x == 0) break;
        cout << x + 1 << ' ';
    }
    cout << '\n';
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
