#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    ll dx1[4] = {1, 0, -1, 0}, dy1[4] = {0, 1, 0, -1};
    ll dx2[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy2[8] = {0, 1, 0, -1, 1, -1, -1, 1};
    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    vector<array<ll, 2>> com1, com2;
    set<ll> H, W;
    function<void(ll, ll)> dfs1 = [&](ll x, ll y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (grid[x][y] != '*') return;
        if (vis1[x][y]) return;
        vis1[x][y] = true;
        com1.push_back({x, y});
        H.insert(x);
        W.insert(y);
        for (ll i = 0; i < 4; ++i) {
            dfs1(x + dx1[i], y + dy1[i]);
        }
    };
    function<void(ll, ll)> dfs2 = [&](ll x, ll y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (grid[x][y] != '*') return;
        if (vis2[x][y]) return;
        vis2[x][y] = true;
        com2.push_back({x, y});
        H.insert(x);
        W.insert(y);
        for (ll i = 0; i < 8; ++i)
            dfs2(x + dx2[i], y + dy2[i]);
    };
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] == '*' && !vis1[i][j]) {
                H.clear(), W.clear(), com1.clear();
                dfs1(i, j);
                sort(all(com1));
                if (sz(com1) != 3 || sz(H) != 2 || sz(W) != 2)
                    return void(cout << "NO\n");
                H.clear(), W.clear(), com2.clear();
                dfs2(i, j);
                sort(all(com2));
                if (sz(com2) != 3 || sz(H) != 2 || sz(W) != 2)
                    return void(cout << "NO\n");
                if (com1 != com2) return void(cout << "NO\n");
            }
        }
    }
    cout << "YES\n";
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
