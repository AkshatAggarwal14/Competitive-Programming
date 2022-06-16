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
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

// visit sum - k, block others.
void Solution() {
    ll n, m, k, sum = 0, sx = 0, sy = 0;
    cin >> n >> m >> k;
    ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<string> grid(n);
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    for (auto &x : grid) cin >> x, sum += count(all(x), '.');
    sum -= k;  // visit others and have "k" remaining
    queue<pair<ll, ll>> bfs;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            if (grid[i][j] == '.') sx = i, sy = j;
    dbg(sum);
    bfs.push({sx, sy});  // start from any point
    vis[sx][sy] = true;
    while (!bfs.empty()) {
        if (sum == 0) break;
        ll X = bfs.front().first, Y = bfs.front().second;
        bfs.pop(), vis[X][Y] = 2;  // marked
        --sum;
        for (ll K = 0; K < 4; ++K) {
            ll nx = X + dx[K], ny = Y + dy[K];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] != '.') continue;
            bfs.push({nx, ny}), vis[nx][ny] = 1;  // visited -> so doesnt get pushed again
        }
    }
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            if (vis[i][j] != 2 && grid[i][j] == '.') grid[i][j] = 'X';  // color unvisited
    for (ll i = 0; i < n; ++i) cout << grid[i] << '\n';
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
    return 0;
}