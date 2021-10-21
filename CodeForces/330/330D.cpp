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
    ll n, m, sx = -1, sy = -1, ex = -1, ey = -1;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 'S') sx = i, sy = j;
            if (adj[i][j] == 'E') ex = i, ey = j;
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(m, -1));  // use as visited
    auto valid = [&](ll x, ll y) -> bool {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (adj[x][y] == 'T' || dist[x][y] != -1) return false;
        return true;
    };
    ll dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    dist[ex][ey] = 0;
    queue<pair<ll, ll>> bfs;
    bfs.emplace(ex, ey);
    while (!bfs.empty()) {
        pair<ll, ll> v = bfs.front();
        bfs.pop();
        for (ll i = 0; i < 4; ++i) {
            ll nx = v.first + dx[i], ny = v.second + dy[i];
            if (!valid(nx, ny)) continue;
            dist[nx][ny] = dist[v.first][v.second] + 1;
            bfs.emplace(nx, ny);
        }
    }

    dbg(dist);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (dist[i][j] != -1 &&
                dist[i][j] <= dist[sx][sy] &&
                adj[i][j] >= '0' &&
                adj[i][j] <= '9') {
                ans += (adj[i][j] - '0');
            }
        }
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}