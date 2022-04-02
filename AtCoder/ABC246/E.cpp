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

ll dx[4] = {1, -1, 1, -1}, dy[4] = {-1, 1, 1, -1};
void test() {
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by, --ax, --ay, --bx, --by;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    queue<array<ll, 2>> bfs;  // {x, y}
    vector<vector<ll>> vis(n, vector<ll>(n, -1));
    auto isValid = [&](ll X, ll Y) -> bool {
        if (X < 0 || Y < 0 || X >= n || Y >= n) return false;
        if (vis[X][Y] != -1) return false;
        if (grid[X][Y] == '#') return false;
        return true;
    };
    bfs.push({ax, ay});
    vis[ax][ay] = 0;
    while (!bfs.empty()) {
        auto it = bfs.front();
        bfs.pop();
        ll X = it[0], Y = it[1];
        for (ll k = 1;; ++k) {
            ll nx = X + k, ny = Y + k;
            if (!isValid(nx, ny)) break;
            bfs.push({nx, ny});
            vis[nx][ny] = vis[X][Y] + 1;
        }
        for (ll k = 1;; ++k) {
            ll nx = X - k, ny = Y + k;
            if (!isValid(nx, ny)) break;
            bfs.push({nx, ny});
            vis[nx][ny] = vis[X][Y] + 1;
        }
        for (ll k = 1;; ++k) {
            ll nx = X + k, ny = Y - k;
            if (!isValid(nx, ny)) break;
            bfs.push({nx, ny});
            vis[nx][ny] = vis[X][Y] + 1;
        }
        for (ll k = 1;; ++k) {
            ll nx = X - k, ny = Y - k;
            if (!isValid(nx, ny)) break;
            bfs.push({nx, ny});
            vis[nx][ny] = vis[X][Y] + 1;
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cerr << vis[i][j] << ' ';
        }
        cerr << '\n';
    }

    cout << vis[bx][by] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
