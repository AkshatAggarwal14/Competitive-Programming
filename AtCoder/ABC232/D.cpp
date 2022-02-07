#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void BFS() {
    ll h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto &x : grid) cin >> x;
    ll res = 0;
    vector<vector<ll>> ans(h, vector<ll>(w, 0));
    queue<array<ll, 2>> bfs;
    bfs.push({0, 0});
    ans[0][0] = 1;
    while (!bfs.empty()) {
        ll x = bfs.front()[0];
        ll y = bfs.front()[1];
        amax(res, ans[x][y]);
        bfs.pop();
        if (grid[x][y] == '#') continue;
        if (x + 1 < h && grid[x + 1][y] == '.' && ans[x + 1][y] < ans[x][y] + 1) {
            ans[x + 1][y] = ans[x][y] + 1;
            bfs.push({x + 1, y});
        }
        if (y + 1 < w && grid[x][y + 1] == '.' && ans[x][y + 1] < ans[x][y] + 1) {
            ans[x][y + 1] = ans[x][y] + 1;
            bfs.push({x, y + 1});
        }
    }
    cout << res << '\n';
}

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
        BFS();
    }
    return 0;
}