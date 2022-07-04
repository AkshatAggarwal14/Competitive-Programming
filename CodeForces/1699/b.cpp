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

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(2, vector<char>(m, '0'));
    for (ll i = 0; i < m; ++i) {
        if (i % 4 == 1 || i % 4 == 2)
            grid[0][i] = '1';
        else
            grid[1][i] = '1';
    }
    for (ll i = 0; i < n / 2; ++i) {
        for (ll j = 0; j < m; ++j) cout << grid[0][j] << " \n"[j == m - 1];
        for (ll j = 0; j < m; ++j) cout << grid[1][j] << " \n"[j == m - 1];
        swap(grid[0], grid[1]);
    }
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
