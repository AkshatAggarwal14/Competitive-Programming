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

void rotate_grid(vector<string> &grid) {
    int n = int(grid.size());
    vector<string> mat(n, string(n, '.'));
    for (int j = 0, a = 0; j < n; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
}

void test() {
    ll n;
    cin >> n;
    vector<string> g1(n);
    for (auto &row : g1) cin >> row;

    vector<vector<vector<pair<int, int>>>> choices(n, vector<vector<pair<int, int>>>(n));
    auto g2 = g1, g3 = g1, g4 = g1;
    rotate_grid(g2);

    rotate_grid(g3);
    rotate_grid(g3);

    rotate_grid(g4);
    rotate_grid(g4);
    rotate_grid(g4);

    ll changes = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            char mxi = max({g1[i][j], g2[i][j], g3[i][j], g4[i][j]});
            changes += 4 * mxi - g1[i][j] - g2[i][j] - g3[i][j] - g4[i][j];
        }
    }

    cout << changes / 4 << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
