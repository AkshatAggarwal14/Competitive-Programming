#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

/*
    best stratergy is to connect {u, u + 1} with cost = 1 if possible,
    thus in worst case cost will be (n - 1)
*/

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> cc_no(n, -1);
    ll cc = 0;
    auto dfs = [&](const auto &self, ll parent) -> void {
        cc_no[parent] = cc;
        for (auto &child : g[parent]) {
            if (cc_no[child] != -1) continue;
            self(self, child);
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (cc_no[i] != -1) continue;
        dfs(dfs, i);
        ++cc;
    }
    vector<vector<ll>> cc_graph(n);
    set<pair<ll, ll>> added;
    for (ll i = 0; i < n; ++i) {
        if (i > 0) {
            ll u = cc_no[i - 1], v = cc_no[i];
            if (u > v) swap(u, v);
            if (!added.count({u, v})) {
                cc_graph[u].push_back(v);
                cc_graph[v].push_back(u);
                added.insert({u, v});
            }
        }
        if (i < n - 1) {
            ll u = cc_no[i + 1], v = cc_no[i];
            if (u > v) swap(u, v);
            if (!added.count({u, v})) {
                cc_graph[u].push_back(v);
                cc_graph[v].push_back(u);
                added.insert({u, v});
            }
        }
    }
    vector<ll> d(n, -1);
    d[0] = 0;
    queue<ll> bfs;
    bfs.push(0);
    while (!bfs.empty()) {
        ll par = bfs.front();
        bfs.pop();
        for (auto &child : cc_graph[par]) {
            if (d[child] == -1) {
                bfs.push(child);
                d[child] = d[par] + 1;
            }
        }
    }
    cout << d[cc_no[n - 1]] << '\n';
}

void USING_DIJKSTRA() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    set<pair<ll, ll>> added;
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 0});
        added.insert({min(u, v), max(u, v)});
    }
    /*
    add all edges of form {i, i + 1} with 1 cost, calculate min using dijkstra.
    */
    for (ll i = 0; i < n - 1; ++i) {
        if (!added.count({i, i + 1})) {
            g[i].push_back({i + 1, 1});
            g[i + 1].push_back({i, 1});
            added.insert({i, i + 1});
        }
    }
    set<pair<ll, ll>> s;
    vector<ll> d(n, INF);
    s.insert({0, 0});
    d[0] = 0;
    while (!s.empty()) {
        ll dis = s.begin()->first;
        ll vertex = s.begin()->second;
        s.erase(s.begin());
        for (pair<ll, ll> x : g[vertex]) {
            ll newDis = dis + x.second;
            ll newVer = x.first;
            if (newDis < d[newVer]) {
                s.erase({d[newVer], newVer});  // erase old distance
                d[newVer] = newDis;            // update
                s.insert({d[newVer], newVer});
            }
        }
    }
    cout << d[n - 1] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        // Solution();
        USING_DIJKSTRA();
    }
    return 0;
}