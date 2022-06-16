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
    ll n, m, k, u, v;
    cin >> n >> m >> k;
    auto get = [&](ll x, ll y) -> ll { return (x - 1) * m + (y - 1); };
    auto getX = [&](ll d) -> ll { return (d / m + 1); };
    auto getY = [&](ll d) -> ll { return (d % m + 1); };
    queue<ll> bfs;
    vector<ll> dist(n * m, -1);
    for (ll i = 0; i < k; ++i) {
        cin >> u >> v;
        bfs.push(get(u, v));  // pushing initial for multisource bfs
        dist[get(u, v)] = 0;
    }
    ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    ll d = 0, mx = -1, my = -1;
    while (!bfs.empty()) {
        ll x = getX(bfs.front()), y = getY(bfs.front());
        bfs.pop();
        for (ll i = 0; i < 4; ++i) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx > n || ny > m || nx < 1 || ny < 1) continue;
            if (dist[get(nx, ny)] != -1) continue;
            bfs.push(get(nx, ny));
            dist[get(nx, ny)] = dist[get(x, y)] + 1;
        }
        if (dist[get(x, y)] >= d) d = dist[get(x, y)], mx = x, my = y;
    }
    cout << mx << ' ' << my << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solution();
    return 0;
}