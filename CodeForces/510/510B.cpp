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
    auto get = [&](ll x, ll y) { return x * m + y; };
    auto getX = [&](ll d) { return d / m; };
    auto getY = [&](ll d) { return d % m; };
    vector<string> g(n, string(m, '.'));
    vector<bool> vis(n * m, false);
    for (auto &x : g) cin >> x;
    auto dfs = [&](const auto &self, ll node, ll p, char color) -> void {
        vis[node] = true;
        for (ll k = 0; k < 4; ++k) {
            ll nx = getX(node) + dx[k];
            ll ny = getY(node) + dy[k];
            ll n_node = get(nx, ny);
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || n_node == p || g[nx][ny] != color)
                continue;
            if (vis[n_node]) {
                cout << "Yes\n";
                exit(0);
            }
            self(self, n_node, node, color);
        }
    };
    //! O(n * m * n * m)
    for (ll i = 0; i < n * m; ++i) {
        fill(all(vis), false);
        dfs(dfs, i, -1, g[getX(i)][getY(i)]);
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