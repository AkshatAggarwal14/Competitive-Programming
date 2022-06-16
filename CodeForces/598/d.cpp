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
char grid[N][N];
ll ans[N][N];
ll n, m, k, cnt, q;
bool vis[N][N], mark[N][N];
ll dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(ll x, ll y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y]) return;
    if (grid[x][y] == '*') {
        cnt++;
        return;
    }
    vis[x][y] = true;
    for (ll i = 0; i < 4; ++i) {
        ll nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}

void dfs(ll x, ll y, ll color) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (mark[x][y] || grid[x][y] == '*') return;
    mark[x][y] = true;
    ans[x][y] = color;
    for (ll i = 0; i < 4; ++i) {
        ll nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny, color);
    }
}

void Solution() {
    cin >> n >> m >> q;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    // calculate for all .
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (vis[i][j] || grid[i][j] == '*') continue;
            cnt = 0;
            dfs(i, j);       // find ans
            dfs(i, j, cnt);  // save ans for all nodes in component
        }
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << ans[x - 1][y - 1] << '\n';
    }
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