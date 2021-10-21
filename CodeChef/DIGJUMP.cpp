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

void Solution() {
    string s;
    cin >> s;
    ll n = s.length();
    if (n == 1) return void(cout << "0\n");
    vector<vector<ll>> g(n), pos(10);
    vector<ll> dist(n, -1), vis(10, 0);
    g[0].push_back(1);
    g[n - 1].push_back(n - 2);
    for (ll i = 1; i <= n - 2; ++i) {
        g[i].push_back(i - 1);
        g[i].push_back(i + 1);
    }
    for (ll i = 0; i < n; ++i) pos[s[i] - '0'].push_back(i);
    queue<ll> bfs;
    bfs.push(0);
    dist[0] = 0;
    while (!bfs.empty()) {
        ll parent = bfs.front();
        bfs.pop();
        for (ll &child : g[parent]) {
            if (dist[child] != -1) continue;
            dist[child] = dist[parent] + 1;
            bfs.push(child);
        }
        if (vis[s[parent] - '0']) continue;
        vis[s[parent] - '0'] = 1;  // do this atmost 10 times, otherwise a useless loop will run many times
        for (ll &idx : pos[s[parent] - '0']) {
            if (dist[idx] != -1) continue;
            dist[idx] = dist[parent] + 1;
            bfs.emplace(idx);
        }
    }
    cout << dist[n - 1] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}