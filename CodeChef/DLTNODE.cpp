#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, u, v;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> deg(n, 0);
    for (ll i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        u--, v--;
        ++deg[u], ++deg[v];
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    //! TLE
    /*
    ll mx = *max_element(deg.begin(), deg.end()), ans = 0, curr = 0, sum = 0;
    vector<ll> vis(n, 0);
    function<void(ll)> answer = [&](ll node) {
        if (node == curr) return;
        vis[node] = 1;
        ans = gcd(ans, a[node]);
        for (ll &child : g[node]) {
            if (vis[child] || child == curr) continue;
            answer(child);
        }
    };
    ll mxsum = 0;
    for (ll i = 0; i < n; ++i) {
        if (deg[i] == mx) {
            vis.resize(n, 0);
            sum = 0;
            curr = i;
            for (ll j = 0; j < n; ++j) {
                if (vis[j] || j == curr) continue;
                ans = 0;
                answer(j);
                sum += ans;
            }
            mxsum = max(mxsum, sum);
        }
    }
    cout << mxsum << '\n';
    */
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}