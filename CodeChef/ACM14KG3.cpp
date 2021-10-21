#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
const ll INF = LLONG_MAX;

void DFS() {
    string a, b;
    cin >> a >> b;
    ll n;
    cin >> n;
    vector<vector<ll>> adj(26);
    vector<ll> vis(26, 0);
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        adj[s[0] - 'a'].push_back(s[3] - 'a');
    }
    ll c = -1;
    vector<set<ll>> check(26);
    auto dfs = [&](const auto &self, ll x) -> void {
        if (vis[x]) return;
        if (c != x) check[c].insert(x);
        vis[x] = 1;
        for (ll &child : adj[x]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };
    if (sz(a) != sz(b)) return void(cout << "NO\n");
    for (ll i = 0; i < 26; ++i) {
        c = i;
        vis.assign(26, 0);
        dfs(dfs, i);
    }
    for (ll i = 0; i < sz(a); ++i) {
        if (a[i] == b[i] || check[a[i] - 'a'].count(b[i] - 'a')) continue;
        return void(cout << "NO\n");
    }
    cout << "YES\n";
}

void Floyd() {
    string a, b;
    cin >> a >> b;
    ll n;
    cin >> n;
    vector<vector<ll>> dist(26, vector<ll>(26, INF));
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dist[s[0] - 'a'][s[3] - 'a'] = 1;
    }
    for (ll i = 0; i < 26; ++i) dist[i][i] = 0;
    // Floyd Warshall to find all costs
    for (ll k = 0; k < 26; ++k) {
        for (ll i = 0; i < 26; ++i) {
            for (ll j = 0; j < 26; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if (sz(a) != sz(b)) return void(cout << "NO\n");
    for (ll i = 0; i < sz(a); ++i) {
        if (dist[a[i] - 'a'][b[i] - 'a'] == INF) {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Floyd();
    // DFS();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}