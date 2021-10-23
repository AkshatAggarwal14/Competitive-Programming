#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> mat(H, vector<ll>(W));
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            cin >> mat[i][j];
        }
    }
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            for (ll i2 = i + 1; i2 < H; ++i2) {
                for (ll j2 = j + 1; j2 < W; ++j2) {
                    if (mat[i][j] + mat[i2][j2] > mat[i2][j] + mat[i][j2]) return void(cout << "No\n");
                }
            }
        }
    }
    cout << "Yes\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}