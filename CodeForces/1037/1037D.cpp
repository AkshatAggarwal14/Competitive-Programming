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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<ll> bfs(n), order(n), fin, vis(n, 0);
    for (ll i = 0; i < n; ++i) cin >> bfs[i], bfs[i]--, order[bfs[i]] = i;

    //! order as adjacency list as input
    for (ll i = 0; i < n; ++i)
        sort(g[i].begin(), g[i].end(), [&](ll a, ll b) {
            return order[a] < order[b];
        });

    // now do usual bfs
    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll node = q.front();
        vis[node] = 1;
        q.pop();
        fin.push_back(node);
        for (ll &child : g[node]) {
            if (vis[child]) continue;
            q.push(child);
        }
    }
    cout << (fin == bfs ? "Yes\n" : "No\n");
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}