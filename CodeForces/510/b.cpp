#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    ll n, m;
    cin >> n >> m;
    vector<string> g(n, string(m, '.'));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (auto &x : g) cin >> x;
    auto dfs = [&](const auto &self, ll X, ll Y, ll Px, ll Py, char color) -> void {
        vis[X][Y] = true;
        for (ll k = 0; k < 4; ++k) {
            ll nx = X + dx[k];
            ll ny = Y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || (nx == Px && ny == Py) || g[nx][ny] != color)
                continue;
            if (vis[nx][ny]) {
                cout << "Yes\n";
                exit(0);
            }
            self(self, nx, ny, X, Y, color);
        }
    };
    //! O(n * m)
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (!vis[i][j]) dfs(dfs, i, j, -1, -1, g[i][j]);
        }
    }
    cout << "No\n";
}
// m2 - for each connected component, edges = nodes - 1

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}