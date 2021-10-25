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

const ll N = 1000;
bool vis[N][N][4][3];  //! [x][y][dir][turns]
ll dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
ll n, m, sx, sy;
char vv[N][N];
bool flag = false;

void Solution() {
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> vv[i][j];
            if (vv[i][j] == 'S') sx = i, sy = j;
        }
    }
    auto dfs = [&](const auto &self, ll x, ll y, ll dir, ll turns) -> void {
        if (turns > 2) return;
        if (x >= n || x < 0 || y >= m || y < 0) return;
        if (vis[x][y][dir][turns]) return;
        if (vv[x][y] == '*') return;
        if (vv[x][y] == 'T') {
            cout << "YES";
            exit(0);
        }
        vis[x][y][dir][turns] = 1;
        for (ll i = 0; i < 4; ++i) self(self, x + dx[i], y + dy[i], i, turns + (i != dir));
    };
    for (ll i = 0; i < 4; ++i) dfs(dfs, sx, sy, i, 0);
    cout << "NO";
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