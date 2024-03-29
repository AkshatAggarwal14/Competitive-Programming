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
    vector<vector<int>> grid(9, vector<int>(9));
    for (auto& x : grid) {
        for (auto& y : x) {
            cin >> y;
        }
    }

    for (int i = 0; i < 9; ++i) {
        set<int> vals;
        for (int j = 0; j < 9; ++j) {
            vals.insert(grid[i][j]);
        }
        if (vals.size() != 9) return void(cout << "No\n");
    }

    for (int j = 0; j < 9; ++j) {
        set<int> vals;
        for (int i = 0; i < 9; ++i) {
            vals.insert(grid[i][j]);
        }
        if (vals.size() != 9) return void(cout << "No\n");
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int begi = 3 * i, begj = 3 * j;
            set<int> vals;
            for (int k = begi; k < begi + 3; ++k) {
                for (int l = begj; l < begj + 3; ++l) {
                    vals.insert(grid[k][l]);
                }
            }
            if (vals.size() != 9) return void(cout << "No\n");
        }
    }

    cout << "Yes\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
