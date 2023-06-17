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
    vector<ll> neigh(n);
    vector<pair<ll, ll>> edges(n);
    for (ll i = 0; i < n; ++i) {
        cin >> neigh[i], --neigh[i];
        ll u = i, v = neigh[i];
        if (u > v) swap(u, v);
        edges[i] = make_pair(u, v);
    }
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    ll m = ll(edges.size());
    vector<vector<ll>> g(n);
    vector<ll> deg(n);
    for (ll i = 0; i < m; ++i) {
        g[edges[i].first].push_back(edges[i].second);
        g[edges[i].second].push_back(edges[i].first);
        ++deg[edges[i].first];
        ++deg[edges[i].second];
    }
    ll ones = 0, components = 0;
    bool one = false;
    vector<bool> visited(n, false);
    function<void(ll)> dfs = [&](ll node) {
        visited[node] = true;
        if (deg[node] == 1) one = true;
        for (auto &child : g[node]) {
            if (!visited[child]) {
                dfs(child);
            }
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            one = false;
            dfs(i);
            ++components;
            if (one) ++ones;
        }
    }
    cout << components - max(ones - 1, 0LL) << ' ' << components << '\n';
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
