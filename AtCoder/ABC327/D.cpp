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
    // CSES Building teams
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    map<ll, set<ll>> mp;

    vector<ll> x(m), y(m);
    vector<pair<ll, ll>> edges;  // store edges to check later
    for (auto& xx : x) cin >> xx;
    for (auto& xx : y) cin >> xx;
    for (ll i = 0; i < m; ++i) {
        if (mp[x[i]].count(y[i])) continue;

        ll u = x[i], v = y[i];
        --u, --v;
        g[u].push_back(v), g[v].push_back(u);
        edges.push_back({u, v});

        mp[x[i]].insert(y[i]);
        mp[y[i]].insert(x[i]);
    }

    vector<ll> d(n, -1);  // use to store ans as well as check visited
    queue<ll> bfs;
    for (ll i = 0; i < n; ++i) {  // kinda like multisouce bfs
        if (d[i] != -1) continue;
        bfs.push(i), d[i] = 1;
        while (!bfs.empty()) {
            ll parent = bfs.front();
            bfs.pop();
            for (ll& child : g[parent]) {
                if (d[child] != -1) continue;
                d[child] = (d[parent] % 2) + 1;
                bfs.push(child);
            }
        }
    }

    for (pair<ll, ll>& t : edges) {
        if (d[t.first] == d[t.second]) {  // if same edge connects equal then NO
            return void(cout << "No\n");
        }
    }
    cout << "Yes\n";
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
