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

void test() {
    vector<string> grid(3);
    for (auto &x : grid) cin >> x;
    for (int i = 0; i < 3; ++i) {
        ll cnt = 1;
        for (int j = 1; j < 3; ++j) {
            if (grid[i][j] == grid[i][0]) {
                ++cnt;
            }
        }
        if (cnt == 3 && grid[i][0] != '.') {
            return void(cout << grid[i][0] << '\n');
        }
    }
    for (int i = 0; i < 3; ++i) {
        ll cnt = 1;
        for (int j = 1; j < 3; ++j) {
            if (grid[j][i] == grid[0][i]) {
                ++cnt;
            }
        }
        if (cnt == 3 && grid[0][i] != '.') {
            return void(cout << grid[0][i] << '\n');
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[1][1] != '.')
        return void(cout << grid[1][1] << '\n');
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != '.')
        return void(cout << grid[1][1] << '\n');
    cout << "DRAW\n";
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
