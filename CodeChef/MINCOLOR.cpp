#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void test() {
    ll n, m;
    cin >> n >> m;
    ll x1, x2, y1, y2;
    vector<vector<ll>> grid(n, vector<ll>(m, -1));
    cin >> x1 >> y1 >> x2 >> y2, --x1, --x2, --y1, --y2;
    grid[x1][y1] = 1, grid[x2][y2] = 2;
    ll NCOLOR = ((x1 + y1) % 2 == (x2 + y2) % 2) ? 3 : 2;
    queue<tuple<ll, ll, ll>> bfs;  // {x, y, col}
    bfs.push(make_tuple(x1, y1, 1));
    while (!bfs.empty()) {
        auto [x, y, col] = bfs.front();
        bfs.pop();
        for (ll k = 0; k < 4; ++k) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != -1) continue;
            ll ncol = ((col == NCOLOR) ? 1 : NCOLOR);
            bfs.push(make_tuple(nx, ny, ncol));
            grid[nx][ny] = ncol;
        }
    }
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cout << grid[i][j] << " \n"[j == m - 1];
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
