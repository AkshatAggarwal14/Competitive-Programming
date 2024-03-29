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

ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void test() {
    ll n;
    cin >> n;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;

    pair<ll, ll> p1 = {-1, -1}, p2;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (grid[i][j] == 'P') {
                if (p1.first != -1) {
                    p2 = {i, j};
                } else {
                    p1 = {i, j};
                }
            }
        }
    }

    vector<vector<vector<vector<ll>>>>
        vis(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(n, INF))));
    queue<array<ll, 4>> bfs;
    bfs.push({p1.first, p1.second, p2.first, p2.second});
    vis[p1.first][p1.second][p2.first][p2.second] = 0;

    while (!bfs.empty()) {
        auto [x1, y1, x2, y2] = bfs.front();
        bfs.pop();

        for (ll k = 0; k < 4; ++k) {
            ll nx1 = x1 + dx[k];
            ll nx2 = x2 + dx[k];
            ll ny1 = y1 + dy[k];
            ll ny2 = y2 + dy[k];

            if (nx1 < 0 or nx1 >= n or ny1 < 0 or ny1 >= n or grid[nx1][ny1] == '#') {
                nx1 = x1, ny1 = y1;
            }

            if (nx2 < 0 or nx2 >= n or ny2 < 0 or ny2 >= n or grid[nx2][ny2] == '#') {
                nx2 = x2, ny2 = y2;
            }

            if (vis[nx1][ny1][nx2][ny2] == INF) {
                vis[nx1][ny1][nx2][ny2] = vis[x1][y1][x2][y2] + 1;
                bfs.push({nx1, ny1, nx2, ny2});
            }
        }
    }

    ll ans = INF;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ans = min(ans, vis[i][j][i][j]);
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << '\n';
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
