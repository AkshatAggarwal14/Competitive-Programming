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

void Solution() {
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for (ll i = 0; i < n; ++i) grid[i][i] = 'Q';
    vector<string> g[] = {{"...Q", "....", ".Q..", "...."}, {"...", ".Q.", "..."}};
    ll idx = (n - sz(g[n % 2])) / 2;
    for (ll i = idx; i < idx + sz(g[n % 2]); ++i) {
        for (ll j = idx; j < idx + sz(g[n % 2]); ++j) {
            grid[i][j] = g[n % 2][i - idx][j - idx];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) cout << grid[i][j];
        cout << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}