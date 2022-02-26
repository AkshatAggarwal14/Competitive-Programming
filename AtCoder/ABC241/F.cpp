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

void Solution() {
    map<pair<ll, ll>, ll> vis;
    map<ll, set<ll>> X, Y;
    ll h, w, n;
    ll sx, sy, gx, gy;
    cin >> h >> w >> n;
    cin >> sx >> sy >> gx >> gy;
    for (ll i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    queue<pair<ll, ll>> bfs;
    bfs.push({sx, sy});
    vis[{sx, sy}] = 0;
    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        auto next_x = Y[y].lower_bound(x);
        if (next_x != Y[y].end() && !vis.count({*next_x - 1, y})) {
            bfs.push({*next_x - 1, y});
            vis[{*next_x - 1, y}] = vis[{x, y}] + 1;
        }
        auto prev_x = next_x;
        if (next_x != Y[y].begin()) {
            --prev_x;
            if (!vis.count({*prev_x + 1, y})) {
                bfs.push({*prev_x + 1, y});
                vis[{*prev_x + 1, y}] = vis[{x, y}] + 1;
            }
        }
        auto next_y = X[x].lower_bound(y);
        if (next_y != X[x].end() && !vis.count({x, *next_y - 1})) {
            bfs.push({x, *next_y - 1});
            vis[{x, *next_y - 1}] = vis[{x, y}] + 1;
        }
        auto prev_y = next_y;
        if (next_y != X[x].begin()) {
            --prev_y;
            if (!vis.count({x, *prev_y + 1})) {
                bfs.push({x, *prev_y + 1});
                vis[{x, *prev_y + 1}] = vis[{x, y}] + 1;
            }
        }
    }
    if (vis.count({gx, gy}))
        cout << vis[{gx, gy}] << '\n';
    else
        cout << "-1\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}