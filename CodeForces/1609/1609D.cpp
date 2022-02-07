#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void Solution() {
    // ans is edges in largest component we can make by joining
    ll n, d, x, y;
    cin >> n >> d;
    vector<vector<bool>> mark(n, vector<bool>(n, false));
    vector<vector<ll>> g(n);
    vector<bool> vis(n, false);
    vector<ll> sz;
    function<ll(ll)> dfs = [&](ll parent) {
        ll cnt = 1;
        vis[parent] = true;
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            cnt += dfs(child);
        }
        return cnt;  // count of nodes in connected component
    };
    for (ll i = 1; i <= d; ++i) {
        cin >> x >> y;
        x--, y--;
        if (!mark[x][y]) {  // to prevent an edge 2 times.
            mark[x][y] = true;
            g[x].push_back(y), g[y].push_back(x);
        }
        fill(all(vis), false);  // reset visited
        sz.clear();             // reset components
        ll rem_edges = i;       // at ith step we can have i edges.
        for (ll j = 0; j < n; ++j) {
            if (vis[j]) continue;
            ll c_sz = dfs(j);
            ll edges = c_sz - 1;  // in star component, 1 root cnt - 1 edges
            rem_edges -= edges;
            sz.push_back(c_sz);
        }
        // now rem_edges contains remaining edges we can use, thus we can join 2 components by 1 edge
        sort(sz.rbegin(), sz.rend());
        ll res = sz[0] - 1;  // edges in largest component
        for (ll j = 1; rem_edges > 0 && j < ssize(sz); j++) {
            res += sz[j];
            rem_edges--;
        }
        cout << res << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}